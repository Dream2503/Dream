/*	Q2. Define a class Box, having basic data members and member function. Write a Main class that create Box objects and compute the volume of the
        Box.
*/

import java.util.Scanner;

class Box {
    private double length, breath, height;

    public Box(double length, double breath, double height) {
        if (length <= 0 || breath <= 0 || height <= 0) {
            System.out.println("The dimensions of the box cannot be negative or zero");
            System.exit(0);
        }
        this.length = length;
        this.breath = breath;
        this.height = height;
    }

    public double computeVolume() {
        return length * breath * height;
    }
}

class Main {
    public static void main(String[] args) {
        Box box1 = createBox("first");
        Box box2 = createBox("second");
        System.out.println("The volume of the first box is " + box1.computeVolume());
        System.out.println("The volume of the second box is " + box2.computeVolume());
    }

    private static Box createBox(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length, breath and height for " + name + " box: ");
        double length = sc.nextDouble();
        double breath = sc.nextDouble();
        double height = sc.nextDouble();
        return new Box(length, breath, height);
    }
}
