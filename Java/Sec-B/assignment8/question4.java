/*	Q4. Write a java program that will create one thread [using extends]. The main thread will read a number and check the number is prime or
		composite and the same time the new thread will check the number palindrome or not.
*/

import java.util.Scanner;

class Palindrome extends Thread {
    private int num;

    public Palindrome(int num) {
        this.num = num;
    }

    public void run() {
        int reverse = 0, temp = num;

        while (temp != 0) {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }
        if (num == reverse) {
            System.out.println(num + " is an palindrome number");
        } else {
            System.out.println(num + " is not an palindrome number");
        }
    }
}

class Main {
    public static void checkPrime(int num) {
        boolean isPrime = true;

        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            System.out.println(num + " is a prime number");
        } else {
            System.out.println(num + " is not a prime number");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        new Palindrome(num).start();
        checkPrime(num);
    }
}