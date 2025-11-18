/*  Q9. Design a class ‘Point’ with data members as x and y. The class should have a parameterized constructor to initialize its data members.
        Define a method distance() which returns the distance between two points.
*/

import java.util.Scanner;

class Point {
    private double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public static double distance(Point point1, Point point2) {
        return Math.sqrt(Math.pow(point2.x - point1.x, 2) + Math.pow(point2.y - point1.y, 2));
    }
}

class Main {
    public static void main(String[] args) {
        Point point1 = createPoint("first");
        Point point2 = createPoint("second");
        double distance = Point.distance(point1, point2);
        System.out.println("Distance between the two Points is: " + distance);
    }

    private static Point createPoint(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter x and y co-ordinates for " + name + " Point: ");
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        return new Point(x, y);
    }
}
