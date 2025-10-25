/*  Q1. Write an exception handling java program to read two numbers num1, num2 and calculate and print the result of num1/num2. If num2 is Zero (0)
        then it will be handled by exception handler and again ask the value of num2. In the exception handler the program should display appropriate
        message to the user.
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter numerator: ");
        int numerator = sc.nextInt();

        while (true) {
            try {
                System.out.print("Enter denominator: ");
                int denominator = sc.nextInt();
                System.out.println("Result of " + numerator + "/" + denominator + " is: " + numerator / denominator);
                return;
            } catch (ArithmeticException e) {
                System.out.println("Denominator cannot be zero, Enter again...");
            }
        }
    }
}
