/*  Q3. Define an abstract class named as Shape, having data members dimOne and dimTwo. Extend this class to create two concrete classes named as
        Rectangle and Triangle. Override the computeArea() method in the sub classes. Invoke the computeArea() method in the main method of another
        Driver class through an abstract class reference variable.
*/

import java.util.Scanner;

abstract class Shape {
    private double dimOne, dimTwo;

    public Shape(double dimOne, double dimTwo) {
        if (dimOne <= 0 || dimTwo <= 0) {
            System.out.println("Dimensions can only be positive");
            System.exit(0);
        }
        this.dimOne = dimOne;
        this.dimTwo = dimTwo;
    }

    public double getDimOne() {
        return dimOne;
    }

    public double getDimTwo() {
        return dimTwo;
    }

    public abstract double computeArea();
}

class Rectangle extends Shape {
    public Rectangle(double length, double breadth) {
        super(length, breadth);
    }

    public double computeArea() {
        return getDimOne() * getDimTwo();
    }
}

class Triangle extends Shape {
    public Triangle(double base, double height) {
        super(base, height);
    }

    public double computeArea() {
        return 0.5 * getDimOne() * getDimTwo();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Shape shape;

        System.out.print("Enter length of Rectangle: ");
        double length = sc.nextDouble();
        System.out.print("Enter breadth of Rectangle: ");
        double breadth = sc.nextDouble();
        shape = new Rectangle(length, breadth);
        System.out.println("Rectangle Area = " + shape.computeArea());

        System.out.print("\nEnter base of Triangle: ");
        double base = sc.nextDouble();
        System.out.print("Enter height of Triangle: ");
        double height = sc.nextDouble();
        shape = new Triangle(base, height);
        System.out.println("Triangle Area = " + shape.computeArea());
    }
}
