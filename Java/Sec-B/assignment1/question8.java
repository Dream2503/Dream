//  Q8. Write a program to reverse a number.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        int reversed = 0;

        while (num != 0) {
            reversed = reversed * 10 + (num % 10);
            num /= 10;
        }
        System.out.println("the reversed number is " + reversed);
    }
}
