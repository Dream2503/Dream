/*  Q12. Write a java program in which main thread should create two child threads (Producer and Consumer). First child thread (Producer) should
         produce ten random integers between 1 to 100 and the second child thread (Consumer) should check whether the generated number is even or odd.
         At the end the second child thread (Consumer) should print total number of even numbers received. Both the threads should wait and notify
         each other wherever necessary.
*/

import java.util.Random;

class Buffer {
    private int value;
    private boolean hasValue = false;

    public synchronized void produce(int product) {
        while (hasValue) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Producer Thread was interrupted");
            }
        }
        value = product;
        hasValue = true;
        System.out.println("Producer produced: " + product);
        notify();
    }

    public synchronized int consume() {
        while (!hasValue) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Consumer Thread was interrupted");
            }
        }
        hasValue = false;
        notify();
        return value;
    }
}

class Producer extends Thread {
    Buffer buffer;

    Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            buffer.produce(random.nextInt(100) + 1);
        }
    }
}

class Consumer extends Thread {
    Buffer buffer;

    Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        int even = 0, odd = 0;

        for (int i = 0; i < 10; i++) {
            int num = buffer.consume();

            if (num % 2 == 0) {
                System.out.println("Consumer consumed EVEN: " + num);
                even++;
            } else {
                System.out.println("Consumer consumed ODD : " + num);
                odd++;
            }
        }
        System.out.println("Total Even: " + even);
        System.out.println("Total Odd: " + odd);
    }
}

class Main {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();
        new Producer(buffer).start();
        new Consumer(buffer).start();
    }
}
