/*  Q6. Define an Interface ScientificCalculator, which is extended from the interface Calculator(Q.5 ). Define the driver class, which create object
        reference of the interface Calculator and perform all basic operation of the calculator and ScientificCalculator.
*/

import java.util.Scanner;

interface Calculator {
    double add(double lhs, double rhs);
    double sub(double lhs, double rhs);
    double mul(double lhs, double rhs);
    double div(double lhs, double rhs);
}

interface ScientificCalculator extends Calculator {
    double sin(double angle);
    double cos(double angle);
    double tan(double angle);
    double sqrt(double num);
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

class DemoScientificCalculator extends DemoCalculator implements ScientificCalculator {
    public double sin(double angle) {
        return Math.sin(Math.toRadians(angle));
    }

    public double cos(double angle) {
        return Math.cos(Math.toRadians(angle));
    }

    public double tan(double angle) {
        return Math.tan(Math.toRadians(angle));
    }

    public double sqrt(double num) {
        if (num < 0) {
            System.out.println("Square root of negative number is undefined");
            System.exit(0);
        }
        return Math.sqrt(num);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Calculator calculator = new DemoCalculator();
        ScientificCalculator scientificCalculator = new DemoScientificCalculator();

        System.out.print("Enter two numbers: ");
        double num1 = sc.nextDouble();
        double num2 = sc.nextDouble();

        System.out.println("Addition: " + calculator.add(num1, num2));
        System.out.println("Subtraction: " + calculator.sub(num1, num2));
        System.out.println("Multiplication: " + calculator.mul(num1, num2));
        System.out.println("Division: " + calculator.div(num1, num2));

        System.out.print("\nEnter angle in degrees for sin, cos, tan: ");
        double angle = sc.nextDouble();

        System.out.println("Sin(" + angle + ") = " + scientificCalculator.sin(angle));
        System.out.println("Cos(" + angle + ") = " + scientificCalculator.cos(angle));
        System.out.println("Tan(" + angle + ") = " + scientificCalculator.tan(angle));

        System.out.print("\nEnter number to compute square root: ");
        double n = sc.nextDouble();
        System.out.println("Sqrt(" + n + ") = " + scientificCalculator.sqrt(n));
    }
}
