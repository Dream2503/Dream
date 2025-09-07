/*	Q7. Define a class Student as follows.
        Data Members :- studentName, studentRoll, studentMarks[5], studentBranch, studentCollegeName
        Member Functions :- displayStudentDetails()
        Define default constructor
        Define parameterized constructor
        Create an array of 10 student object. Display the details information about the student who has secured the highest average mark.
*/

import java.util.Scanner;

class Student {
    private String studentName, studentBranch, studentCollageName;
    private int studentRoll;
    private double[] studentMarks;

    public Student() {
        this.studentName = "Unknown";
        this.studentRoll = 1;
        this.studentMarks = new double[5];
        this.studentBranch = "N/A";
        this.studentCollageName = "Unknown";
    }

    public Student(String studentName, int studentRoll, double[] studentMarks, String studentBranch, String studentCollageName) {
        if (studentRoll <= 0) {
            System.out.println("Roll no. cannot be negative or zero");
            System.exit(0);
        }
        for (double mark : studentMarks) {
            if (mark < 0.0 || mark > 100.0) {
                System.out.println("Marks cannot be negative or more than 100");
                System.exit(0);
            }
        }
        this.studentName = studentName;
        this.studentRoll = studentRoll;
        this.studentMarks = studentMarks;
        this.studentBranch = studentBranch;
        this.studentCollageName = studentCollageName;
    }

    public double[] getStudentMarks() {
        return studentMarks;
    }

    public void displayStudentDetails() {
        System.out.println("Name: " + studentName);
        System.out.println("Roll no.: " + studentRoll);
        System.out.print("Marks in 5 subjects: ");

        for (double mark : studentMarks) {
            System.out.print(mark + " ");
        }
        System.out.println("\nBranch: " + studentBranch);
        System.out.println("Collage Name: " + studentCollageName);
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student[] students = new Student[10];

        for (int i = 0; i < 10; i++) {
            System.out.println("Enter the details of Student" + (i + 1) + ":");
            System.out.println("Enter the name: ");
            String name = sc.nextLine();
            System.out.println("Enter the roll no.: ");
            int roll = sc.nextInt();
            System.out.println("Enter the marks in 5 subjects: ");
            double[] marks = new double[5];

            for (int j = 0; j < 5; j++) {
                marks[j] = sc.nextDouble();
            }
            System.out.println("Enter the branch: ");
            String branch = sc.nextLine();
            System.out.println("Enter the college name: ");
            String collegeName = sc.nextLine();
            students[i] = new Student(name, roll, marks, branch, collegeName);
        }
        Student topper = students[0];

        for (Student student : students) {
            if (average(topper.getStudentMarks()) < average(student.getStudentMarks())) {
                topper = student;
            }
        }
        System.out.println("The student with highest marks is:");
        topper.displayStudentDetails();
    }

    private static double average(double[] marks) {
        double sum = 0;

        for (double mark : marks) {
            sum += mark;
        }
        return sum / marks.length;
    }
}
