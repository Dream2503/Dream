//  Q3. Write a program to calculate the roots of a quadratic equation.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the 3 coefficients of the quadratic equation: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        double det = b * b - 4 * a * c;

        if (det < 0) {
            System.out.println("No real roots exists");
        } else {
            det = Math.sqrt(det);
            double root1 = (-b + det) / 2 * a;

            if (det == 0) {
                System.out.println("The real and equal root is " + root1);
            } else {
                double root2 = (-b - det) / 2 * a;
                System.out.println("The real and distinct roots are " + root1 + " and " + root2);
            }
        }
    }
}
