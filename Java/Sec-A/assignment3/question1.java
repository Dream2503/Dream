/*  Q1. Define a class Point, which can be used to create two-dimensional points. Create three objects of Point class and check, these point are
        non-collinear.
*/

import java.util.Scanner;

class Point {
    private double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public static boolean areCollinear(Point point1, Point point2, Point point3) {
        double area = point1.x * (point2.y - point3.y) + point2.x * (point3.y - point1.y) + point3.x * (point1.y - point2.y);
        return area == 0.0;
    }
}

class Main {
    public static void main(String[] args) {
        Point point1 = createPoint("first");
        Point point2 = createPoint("second");
        Point point3 = createPoint("third");

        if (Point.areCollinear(point1, point2, point3)) {
            System.out.println("The above points are collinear");
        } else {
            System.out.println("The above points are not collinear");
        }
    }

    private static Point createPoint(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter x and y co-ordinates for " + name + " Point: ");
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        return new Point(x, y);
    }
}
