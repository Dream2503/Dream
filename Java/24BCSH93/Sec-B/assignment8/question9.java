/*  Q9. Write a java program that will compute product of two 1D arrays using multithreading. The program should read two 1D arrays of same size from
        the user. First thread should multiply the corresponding elements present in the odd index position and second thread should multiply the
        corresponding elements present in the even index position. Main thread should display the result.
*/

import java.util.Scanner;

class Multiply extends Thread {
    int[] lhs, rhs, res;
    String type;

    public Multiply(int[] lhs, int[] rhs, int[] res, String type) throws IllegalArgumentException {
        if (!type.equals("even") && !type.equals("odd")) {
            throw new IllegalArgumentException("Invalid type argument. Can only be (\"even\" or \"odd\")");
        }
        this.lhs = lhs;
        this.rhs = rhs;
        this.res = res;
        this.type = type;
    }

    public void run() {
        for (int i = type.equals("even") ? 0 : 1; i < lhs.length; i += 2) {
            res[i] = lhs[i] * rhs[i];
        }
    }
}

class Main {
    public static int[] createArray(int size, String name) {
        Scanner sc = new Scanner(System.in);
        int[] array = new int[size];
        System.out.print("Enter the elements of " + name + " array: ");

        for (int i = 0; i < size; i++) {
            array[i] = sc.nextInt();
        }
        return array;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();
        int[] lhs = createArray(size, "first");
        int[] rhs = createArray(size, "second");
        int[] res = new int[size];
        Thread thread1 = new Multiply(lhs, rhs, res, "even");
        Thread thread2 = new Multiply(lhs, rhs, res, "odd");
        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Thread was interrupted");
        }
        System.out.print("Resultant array after Multiplication:");

        for (int value : res) {
            System.out.print(" " + value);
        }
        System.out.println();
    }
}