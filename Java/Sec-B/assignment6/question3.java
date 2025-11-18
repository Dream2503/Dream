/*	Q3. Create an abstract class 'Shape' with three abstract methods namely 'RectangleArea' taking two parameters, 'SquareArea' and 'CircleArea'
 		taking one parameter each. The parameters of 'RectangleArea' are its length and breadth, that of 'SquareArea' is its side and that of
 		'CircleArea' is its radius. Now create another class 'Area' containing all the three methods 'RectangleArea', 'SquareArea' and 'CircleArea'
 		for printing the area of rectangle, square and circle respectively. Create an object of class 'Area' and call all the three methods.
*/

import java.util.Scanner;

abstract class Shape {
    public abstract void rectangleArea(double length, double breadth);
    public abstract void squareArea(double side);
    public abstract void circleArea(double radius);
}

class Area extends Shape {
    public void rectangleArea(double length, double breadth) {
        System.out.println("Area of the Rectangle is: " + length * breadth);
    }

    public void squareArea(double side) {
        System.out.println("Area of the Square is: " + side * side);
    }

    public void circleArea(double radius) {
        System.out.println("Area of the Circle is: " + Math.PI * radius * radius);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Shape shape = new Area();

        System.out.print("Enter length and breadth for the Rectangle: ");
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        shape.rectangleArea(length, breadth);

        System.out.print("\nEnter side for the Square: ");
        double side = sc.nextDouble();
        shape.squareArea(side);

        System.out.print("\nEnter radius for the Circle: ");
        double radius = sc.nextDouble();
        shape.circleArea(radius);
    }
}
