package btech;

public class Student {
    private int rollNo;
    private String name;
    private double[] marks;

    public Student(int rollNo, String name, double[] marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    public double[] getMarks() {
        return marks;
    }

    public void display() {
        System.out.println("\nRoll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("-----MARKS------");

        for (int i = 0; i < 3; i++) {
            System.out.println("Subject " + (i + 1) + ": " + marks[i]);
        }
        System.out.println("----------------");
    }
}
