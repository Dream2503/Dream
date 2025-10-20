/*	Q2. Define an interface Calculator which has the basic methods add(), sub(), mul() and div(). Define a concrete class named as DemoCalculator
        that implements the interface. Define the Main class, which create object reference of the interface Calculator and perform all basic
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
        Calculator calculator = new DemoCalculator();
        System.out.print("Enter two numbers: ");
        double lhs = sc.nextDouble();
        double rhs = sc.nextDouble();

        System.out.println("\nAddition: " + calculator.add(lhs, rhs));
        System.out.println("Subtraction: " + calculator.sub(lhs, rhs));
        System.out.println("Multiplication: " + calculator.mul(lhs, rhs));
        System.out.println("Division: " + calculator.div(lhs, rhs));
    }
}
