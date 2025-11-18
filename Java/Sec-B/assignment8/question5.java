/*	Q5. Write a java program that will create one child thread. The child thread has to display all odd numbers between start and end, and the main
 		thread will display all the even numbers between start and end.
*/

import java.util.Scanner;

class Odd extends Thread {
    private int start, end;

    public Odd(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public void run() {
        System.out.print("Odd numbers between " + start + " and " + end + " are:");

        for (int i = start; i <= end; i++) {
            if (i % 2 == 1) {
                System.out.print(" " + i);
            }
        }
        System.out.println();
    }
}

class Main {
    public static void printEven(int start, int end) {
        System.out.print("Even numbers between " + start + " and " + end + " are:");

        for (int i = start; i <= end; i++) {
            if (i % 2 == 0) {
                System.out.print(" " + i);
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int start = sc.nextInt();
        int end = sc.nextInt();
        Thread thread = new Odd(start, end);
        thread.start();

        try {
            thread.join();
        } catch (InterruptedException e) {
            System.out.println("Thread was interrupted");
        }
        printEven(start, end);
    }
}