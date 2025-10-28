/*  Q10. Write a simple Java thread program to compute the sum of n natural numbers. The program should read the number of threads m and value of n
         from the user. Each of the threads should add its share of assigned number to a global variable. When all the threads are done, the global
         variable should contain the result. The program should use a Synchronized block to make sure that only one thread is updating the global
         variable at a given time.
*/

import java.util.Scanner;

class SumOfNaturalNumber implements Runnable {
    private int n, i = 1, sum = 0;

    public SumOfNaturalNumber(int n) throws IllegalArgumentException {
        if (n <= 0) {
            throw new IllegalArgumentException("Enter valid Natural Number. n: " + n);
        }
        this.n = n;
    }

    public int getSum() {
        return sum;
    }

    public void run() {
        while (i <= n) {
            synchronized (this) {
                sum += i++;
            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number to calculate the sum: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of threads: ");
        int m = sc.nextInt();
        SumOfNaturalNumber sumOfNaturalNumber = new SumOfNaturalNumber(n);
        Thread[] threads = new Thread[m];

        for (int i = 0; i < m; i++) {
            threads[i] = new Thread(sumOfNaturalNumber);
        }
        for (int i = 0; i < m; i++) {
            threads[i].start();
        }
        for (int i = 0; i < m; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                System.out.println("Thread was interrupted");
            }
        }
        System.out.println("Sum of the first " + n + " Natural Numbers are: " + sumOfNaturalNumber.getSum());
    }
}
