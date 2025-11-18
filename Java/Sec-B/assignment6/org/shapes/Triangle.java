package org.shapes;

public class Triangle {
    private double base, height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double area() {
        return 0.5 * base * height;
    }

    public double perimeter() {
        return base + height + Math.sqrt(base * base + height * height);
    }
}
