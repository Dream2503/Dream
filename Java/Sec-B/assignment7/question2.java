/*  Q2. Write a java program to read two numbers x and y and calculate x/(x-y). The program should check the value of x-y. Before dividing with x, it
        should throw an exception if x-y is zero. In the exception handler the program should display appropriate message to the user.
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int x = sc.nextInt();
        int y = sc.nextInt();

        try {
            if (x - y == 0) {
                throw new ArithmeticException("Division by zero occurred");
            } else {
                System.out.printf("Result: %d/(%d-%d) is: %d\n", x, x, y, x / (x - y));
            }
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }
    }
}