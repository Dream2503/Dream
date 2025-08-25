//	Q8. Write a program to find out the binary equivalent of any inputted decimal number.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        int bin = 0, mul = 1;

        while (num != 0) {
            bin = bin + (num % 2) * mul;
            num /= 2;
            mul *= 10;
        }
        System.out.println("The binary equivalent is " + bin);
    }
}
