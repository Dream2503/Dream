/*  Q6. Define a class Student having the attribute sic, name, branch and cgpa. Write 2 methods to accept and display the student details.
        Read the details of 5 students using an array of Student class object. Display the student details who have secured the highest CGPA.
*/

import java.util.Scanner;

class Student {
    private String sic, name, branch;
    private double cgpa;

    public void initialize(String sic, String name, String branch, double cgpa) {
        if (cgpa < 0.0) {
            System.out.println("CGPA cannot be negative");
            System.exit(0);
        }
        this.sic = sic;
        this.name = name;
        this.branch = branch;
        this.cgpa = cgpa;
    }

    public void display() {
        System.out.println("SIC: " + sic);
        System.out.println("Name: " + name);
        System.out.println("Branch: " + branch);
        System.out.println("CGPA: " + cgpa);
        System.out.println();
    }

    public double getCgpa() {
        return cgpa;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student[] students = new Student[5];
        System.out.println("Enter details of 5 Students: ");

        for (int i = 0; i < 5; i++) {
            students[i] = new Student();
            System.out.print("Enter SIC, Name, Branch and CGPA of the Student" + (i + 1) + ": ");
            String sic = sc.next();
            String name = sc.next();
            String branch = sc.next();
            double cgpa = sc.nextDouble();
            students[i].initialize(sic, name, branch, cgpa);
        }
        System.out.println("\nThe student details are: ");
        Student highestCgpa = students[0];

        for (Student student : students) {
            if (student.getCgpa() > highestCgpa.getCgpa()) {
                highestCgpa = student;
            }
            student.display();
        }
        System.out.println("Student with highest CGPA is:");
        highestCgpa.display();
    }
}
