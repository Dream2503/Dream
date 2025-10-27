/*	Q7. Write a java program that will create two threads. The main thread will read a number and one thread will print the multiplication table of
		the entered number and the same time the other thread will find the factorial of the entered number.
		Note: Main thread has to wait until other two threads have completed their task.
*/

import java.util.Scanner;

class MultiplicationTable extends Thread {
    private int num;

    public MultiplicationTable(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("Multiplication Table for " + num + ":");

        for (int i = 1; i <= 10; i++) {
            System.out.println(num + " * " + i + " = " + num * i);
        }
    }
}

class Factorial extends Thread {
    private int num;

    public Factorial(int num) {
        this.num = num;
    }

    public void run() throws IllegalArgumentException {
        int fact = 1;

        if (num < 0) {
            throw new IllegalArgumentException("Factorial of negative number is undefined");
        }
        for (int i = 2; i <= num; i++) {
            fact *= i;
        }
        System.out.println("Factorial of " + num + " is: " + fact);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a numbers: ");
        int num = sc.nextInt();
        Thread thread1 = new MultiplicationTable(num);
        thread1.start();

        try {
            thread1.join();
        } catch (InterruptedException e) {
            System.out.println("Thread was interrupted");
        }
        Thread thread2 = new Factorial(num);
        thread2.start();

        try {
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Thread was interrupted");
        }
    }
}