/*	Q7. Define a class Student as follows.
        Data Members :- name, roll, marks[5], branch, collegeName
        Member Functions :- display()
        Define default constructor
        Define parameterized constructor
        Create an array of 5 student object. Display the details information about the student who has secured the highest average mark.
*/

import java.util.Scanner;

class Student {
    private String name, branch, collegeName;
    private int roll;
    private double[] marks;

    public Student() {
        this.name = "Unknown";
        this.roll = 1;
        this.marks = new double[5];
        this.branch = "N/A";
        this.collegeName = "Unknown";
    }

    public Student(String name, int roll, double[] marks, String branch, String collegeName) {
        if (roll <= 0) {
            System.out.println("Roll no. can only be positive");
            System.exit(0);
        }
        for (double mark : marks) {
            if (mark < 0.0 || mark > 100.0) {
                System.out.println("Marks cannot be negative or more than 100");
                System.exit(0);
            }
        }
        this.name = name;
        this.roll = roll;
        this.marks = marks;
        this.branch = branch;
        this.collegeName = collegeName;
    }

    public double[] getMarks() {
        return marks;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Roll no.: " + roll);
        System.out.print("Marks in 5 subjects: ");

        for (double mark : marks) {
            System.out.print(mark + " ");
        }
        System.out.println("\nBranch: " + branch);
        System.out.println("Collage Name: " + collegeName);
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student[] students = new Student[5];
        System.out.println("Enter the details of 5 Students:");

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter the Name, Roll no., marks in 5 subjects, Branch and Collage Name of Student" + (i + 1) + ": ");
            String name = sc.nextLine();
            int roll = sc.nextInt();
            double[] marks = new double[5];

            for (int j = 0; j < 5; j++) {
                marks[j] = sc.nextDouble();
            }
            String branch = sc.nextLine();
            String collegeName = sc.nextLine();
            students[i] = new Student(name, roll, marks, branch, collegeName);
        }
        System.out.println("The details of the 5 Students are:");
        Student topper = students[0];

        for (Student student : students) {
            if (average(topper.getMarks()) < average(student.getMarks())) {
                topper = student;
            }
            student.display();
        }
        System.out.println("The student with highest average marks is:");
        topper.display();
    }

    private static double average(double[] marks) {
        double sum = 0;

        for (double mark : marks) {
            sum += mark;
        }
        return sum / marks.length;
    }
}
