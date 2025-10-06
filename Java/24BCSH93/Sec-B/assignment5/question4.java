/*	Q4. Define an abstract class named “Figure”, having data members dim1 and dim2. Extend this class to create two concrete classes named Rectangle
        and Triangle. Override the getArea() method in the sub classes. Invoke the getArea() method in the main method of another Main class through
        the abstract class reference variable.
*/

import java.util.Scanner;

abstract class Figure {
    protected double dim1, dim2;

    protected static void validate(String name, double value) {
        if (value <= 0.0) {
            System.out.println(name + " can only be positive");
        }
    }

    abstract double getArea();
}

class Rectangle extends Figure {
    public Rectangle(double length, double breadth) {
        validate("Length", length);
        validate("Breadth", breadth);
        this.dim1 = length;
        this.dim2 = breadth;
    }

    public double getArea() {
        return dim1 * dim2;
    }
}

class Triangle extends Figure {
    public Triangle(double base, double height) {
        validate("Base", base);
        validate("Height", height);
        this.dim1 = base;
        this.dim2 = height;
    }

    public double getArea() {
        return 0.5 * dim1 * dim2;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Figure figure;

        System.out.print("Enter the length and breadth of Rectangle: ");
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        figure = new Rectangle(length, breadth);
        System.out.println("Area of the Rectangle is: " + figure.getArea());

        System.out.print("\nEnter the base and height of Triangle: ");
        double base = sc.nextDouble();
        double height = sc.nextDouble();
        figure = new Triangle(base, height);
        System.out.println("Area of the Triangle is: " + figure.getArea());
    }
}
