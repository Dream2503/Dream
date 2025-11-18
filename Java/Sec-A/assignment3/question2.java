/*	Q2. Define a class Box, having basic data members and member function. Write a Main class that create Box objects and compute the volume of the
        Box.
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
        Box box1 = createBox("first");
        Box box2 = createBox("second");
        System.out.println("The volume of the first Box is " + box1.computeVolume());
        System.out.println("The volume of the second Box is " + box2.computeVolume());
    }

    private static Box createBox(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length, breath and height for " + name + " Box: ");
        double length = sc.nextDouble();
        double breath = sc.nextDouble();
        double height = sc.nextDouble();
        return new Box(length, breath, height);
    }
}
