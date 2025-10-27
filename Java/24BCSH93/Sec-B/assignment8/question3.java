/*  Q3. Write a java program that will create one thread [using Runnable interface]. The main thread will read a number and the newly created thread
        checks the number is Armstrong number or not.
*/

import java.util.Scanner;

class Armstrong implements Runnable {
    private int num;

    public Armstrong(int num) {
        this.num = num;
    }

    public void run() {
        int length = (int)Math.log10(num) + 1;
        int armstrong = 0, temp = num;

        while (temp != 0) {
            armstrong += (int)Math.pow(temp % 10, length);
            temp /= 10;
        }
        if (num == armstrong) {
            System.out.println(num + " is an armstrong number");
        } else {
            System.out.println(num + " is not an armstrong number");
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        new Thread(new Armstrong(sc.nextInt())).start();
    }
}