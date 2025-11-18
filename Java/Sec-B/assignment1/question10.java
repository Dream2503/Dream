//  Q10. Write a program to find out the sum of the individual digits of a number.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        int sum = 0;

        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        System.out.println("The sum of the digits is " + sum);
    }
}
