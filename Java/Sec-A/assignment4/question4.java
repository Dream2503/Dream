/*  Q4. Create a class called Student that keeps track of the total number of students created. Each student has a name and a rollNumber. Use a
        static data member to count the total students and a static method to display this count.

        Requirements:
            Class Student should have:
            •	A private instance variable name (String).
            •	A private instance variable rollNumber (int).
            •	A static variable totalStudents (int) to keep track of the number of students.
            •	A constructor that takes name and rollNumber, sets the values, and increments totalStudents.
            •	A static method getTotalStudents() that returns the value of totalStudents.
            •	A method display() that displays the student's details (name and rollNumber).

            In the main method:
            •	Create multiple Student objects.
            •	Display details of each student.
            •	Display the total number of students using the static method.
*/

import java.util.Scanner;

class Student {
    private String name;
    private int rollNumber;
    private static int totalStudents = 0;

    public Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
        totalStudents++;
    }

    public static int getTotalStudents() {
        return totalStudents;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Roll number: " + rollNumber);
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the total number of Students you want to enter: ");
        int size = sc.nextInt();
        Student[] students = new Student[size];
        System.out.println("\nEnter the details of " + size + " Students:");

        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Name, Roll number of Student" + (i + 1) + ": ");
            String name = sc.next();
            int rollNumber = sc.nextInt();
            students[i] = new Student(name, rollNumber);
        }
        System.out.println("\nThe details of the " + size + " Students are:");

        for (Student student : students) {
            student.display();
        }
        System.out.println("Total number of Students are: " + Student.getTotalStudents());
    }
}
