/*	Q6. Write a java program to create two threads. First thread should find the square of the number, second thread should find the sum of the
        digits of the number.
*/

import java.util.Scanner;

class Square extends Thread {
    private int num;

    public Square(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("Square of " + num + " is: " + num * num);
    }
}

class DigitSum extends Thread {
    private int num;

    public DigitSum(int num) {
        this.num = num;
    }

    public void run() {
        int sum = 0, temp = num;

        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        System.out.println("Sum of the digits of " + num + " is: " + sum);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a numbers: ");
        int num = sc.nextInt();
        new Square(num).start();
        new DigitSum(num).start();
    }
}