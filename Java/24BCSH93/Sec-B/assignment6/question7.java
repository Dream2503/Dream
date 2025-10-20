/*  Q7. Create a sub-package called arithmetic under the package btech. The arithmetic package should contain a class MyMath having methods to deal
        with different arithmetic operations (addition, subtraction, multiplication, division and mod). Create a class Main containing the main method
        which will use the methods of sub-package arithmetic.
*/

import java.util.Scanner;

import btech.arithmetic.MyMath;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        double lhs = sc.nextDouble();
        double rhs = sc.nextDouble();

        System.out.println("\nAddition: " + MyMath.add(lhs, rhs));
        System.out.println("Subtraction: " + MyMath.sub(lhs, rhs));
        System.out.println("Multiplication: " + MyMath.mul(lhs, rhs));
        System.out.println("Division: " + MyMath.div(lhs, rhs));
        System.out.println("Modulus: " + MyMath.mod(lhs, rhs));
    }
}
