/*	Q7. Define a class ‘Box’ that uses a parameterized constructor to initialize the dimensions of a box. The dimensions of the Box are length,
        breath, height. The class should have a method that can return the volume of the box. Create an object of the Box class and test the
        functionalities [use this keyword].
*/

import java.util.Scanner;

class Box {
    private double length, breath, height;

    public Box(double length, double breath, double height) {
        validate(length, "Length");
        validate(breath, "Breath");
        validate(height, "Height");
        this.length = length;
        this.breath = breath;
        this.height = height;
    }

    public double computeVolume() {
        return length * breath * height;
    }

    private static void validate(double value, String name) {
        if (value <= 0) {
            System.out.println(name + " can only be positive");
            System.exit(0);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length, breath and height for a Box: ");
        double length = sc.nextDouble();
        double breath = sc.nextDouble();
        double height = sc.nextDouble();
        Box box = new Box(length, breath, height);
        System.out.println("The volume of the Box is " + box.computeVolume());
    }
}
