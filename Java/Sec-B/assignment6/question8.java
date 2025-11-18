/*  Q8. Create a sub-package named shapes under a package org. Create some classes in the package representing some common geometric shapes like
        Square, Triangle, Circle and so on. The classes should contain the area() and perimeter() methods in them. Compile the package. Use this
        package to find area and perimeter of different shapes as chosen by the user.
*/

import java.util.Scanner;

import org.shapes.Circle;
import org.shapes.Square;
import org.shapes.Triangle;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Choose a shape to calculate:");
        System.out.println("1. Square");
        System.out.println("2. Circle");
        System.out.println("3. Triangle");
        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();
        System.out.println();

        switch (choice) {
            case 1:
                System.out.print("Enter side of the square: ");
                double side = sc.nextDouble();
                Square square = new Square(side);
                System.out.println("Area: " + square.area());
                System.out.println("Perimeter: " + square.perimeter());
                break;

            case 2:
                System.out.print("Enter radius of the circle: ");
                double radius = sc.nextDouble();
                Circle circle = new Circle(radius);
                System.out.println("Area: " + circle.area());
                System.out.println("Perimeter: " + circle.perimeter());
                break;

            case 3:
                System.out.print("Enter base of the triangle: ");
                double base = sc.nextDouble();
                System.out.print("Enter height of the triangle: ");
                double height = sc.nextDouble();
                Triangle triangle = new Triangle(base, height);
                System.out.println("Area: " + triangle.area());
                System.out.println("Perimeter: " + triangle.perimeter());
                break;

            default:
                System.out.println("Invalid choice!");
        }
    }
}
