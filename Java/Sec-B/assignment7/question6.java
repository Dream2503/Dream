/*  Q6. Write a program that prompts the user to enter a length in feet and inches and outputs the equivalent length in centimetres. If the user
        enters a negative number or a non-digit number, throw and handle an appropriate exception and prompt the user to enter another set of numbers.
*/

import java.util.InputMismatchException;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        while (true) {
            try {
                Scanner sc = new Scanner(System.in);
                System.out.print("Enter the length in feet and inches: ");
                int feet = sc.nextInt();
                int inches = sc.nextInt();

                if (feet < 0.0 || inches < 0.0) {
                    throw new IllegalArgumentException();
                }
                double centimeter = (feet * 12 + inches) * 2.54;
                System.out.println("Equivalent length in centimeters: " + centimeter);
                return;
            } catch (InputMismatchException e) {
                System.out.println("Enter a valid number containing digits");
            } catch (IllegalArgumentException e) {
                System.out.println("Negative value(s) was/were entered. Try again...");
            }
        }
    }
}
