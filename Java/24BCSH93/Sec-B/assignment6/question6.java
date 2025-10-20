/*  Q6. Create a Package btech which has one class Student. Accept student detail through parameterized constructor of Student class. Write a method
        display() to display the student details. Create another class Main containing the main method which will use the package btech and calculate
        total marks and percentage of marks.
*/

import java.util.Scanner;

import btech.Student;

class Main {
    public static double getTotal(double[] marks) {
        double total = 0.0;

        for (double mark : marks) {
            total += mark;
        }
        return total;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Roll no:= ");
        int rollNo = sc.nextInt();
        System.out.print("Enter Name:= ");
        String name = sc.next();
        System.out.print("Enter marks in 3 subjects:= ");
        double[] marks = new double[3];

        for (int i = 0; i < 3; i++) {
            marks[i] = sc.nextDouble();
        }
        Student student = new Student(rollNo, name, marks);
        student.display();
        double totalMarks = getTotal(student.getMarks());
        double percentage = totalMarks / 3;
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Percentage: " + percentage);
    }
}
