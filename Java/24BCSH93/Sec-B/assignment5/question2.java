/*	Q2. Create a class Figure with instance members dim1 and dim2. Use constructor and area() that returns the area of figure. Create a derived class
		Rectangle derived from Figure and area() that returns the area of rectangle. Create another derived class Triangle and Square that has area()
		which returns area of Triangle and Square respectively. Derived class have appropriate constructor. Using method overriding concept test the
		functionalities of derived class by creating objects and super class memory references in Main class.
*/

import java.util.Scanner;

abstract class Figure {
    protected double dim1, dim2;

    public Figure(double dim1, double dim2) {
        validate("First Dimension", dim1);
        validate("Second Dimension", dim2);
        this.dim1 = dim1;
        this.dim2 = dim2;
    }

    protected static void validate(String name, double value) {
        if (value <= 0.0) {
            System.out.println(name + " can only be positive");
        }
    }

    abstract double area();
}

class Rectangle extends Figure {
    public Rectangle(double length, double breadth) {
        super(length, breadth);
    }

    public double area() {
        return dim1 * dim2;
    }
}

class Triangle extends Figure {
    public Triangle(double base, double height) {
        super(base, height);
    }

    public double area() {
        return 0.5 * dim1 * dim2;
    }
}

class Square extends Figure {
    public Square(double side) {
        super(side, side);
    }

    public double area() {
        return dim1 * dim1;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Figure figure;

        System.out.print("Enter the length and breadth of the Rectangle: ");
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        figure = new Rectangle(length, breadth);
        System.out.println("Area of the Rectangle is: " + figure.area());

        System.out.print("\nEnter the base and height of the Triangle: ");
        double base = sc.nextDouble();
        double height = sc.nextDouble();
        figure = new Triangle(base, height);
        System.out.println("Area of the Triangle is: " + figure.area());

        System.out.print("\nEnter the side of the Square: ");
        double side = sc.nextDouble();
        figure = new Square(side);
        System.out.println("Area of the Square is: " + figure.area());
    }
}
