//  Q12. Write a program to test whether a number is positive, negative or equal to zero.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        if (num < 0) {
            System.out.println(num + " is negative number");
        } else if (num > 0) {
            System.out.println(num + " is positive number");
        } else {
            System.out.println(num + " is a zero");
        }
    }
}
