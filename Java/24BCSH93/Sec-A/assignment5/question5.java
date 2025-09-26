/*  Q5. Define an interface Calculator which has the basic methods add(), sub(), mul() and div(). Define a concrete class named as DemoCalculator
        that implements the interface. Define the driver class, which create object reference of the interface Calculator and perform all basic
        operation of the calculator.
*/

import java.util.Scanner;

interface Calculator {
    double add(double lhs, double rhs);
    double sub(double lhs, double rhs);
    double mul(double lhs, double rhs);
    double div(double lhs, double rhs);
}

class DemoCalculator implements Calculator {
    public double add(double lhs, double rhs) {
        return lhs + rhs;
    }

    public double sub(double lhs, double rhs) {
        return lhs - rhs;
    }

    public double mul(double lhs, double rhs) {
        return lhs * rhs;
    }

    public double div(double lhs, double rhs) {
        if (rhs == 0) {
            System.out.println("Division by Zero");
            System.exit(0);
        }
        return lhs / rhs;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Calculator calc = new DemoCalculator();

        System.out.print("Enter two numbers: ");
        double num1 = sc.nextDouble();
        double num2 = sc.nextDouble();

        System.out.println("\nAddition: " + calc.add(num1, num2));
        System.out.println("Subtraction: " + calc.sub(num1, num2));
        System.out.println("Multiplication: " + calc.mul(num1, num2));
        System.out.println("Division: " + calc.div(num1, num2));
    }
}
