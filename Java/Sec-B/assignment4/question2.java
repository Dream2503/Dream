/*  Q2. Write a program to create a class named 'Student' with members 'name', 'roll', ‘branch’. Declare two methods to input the student details and
        display the details of the student. Create a Main class to test the functionalities of the above class.
*/

import java.util.Scanner;

class Student {
    private String name, branch;
    private int roll;

    public void initialize(String name, int roll, String branch) {
        if (roll <= 0) {
            System.out.println("Roll No. can only be positive");
            System.exit(0);
        }
        this.name = name;
        this.roll = roll;
        this.branch = branch;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Roll: " + roll);
        System.out.println("Branch: " + branch);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student student = new Student();
        System.out.print("Enter name, roll and branch of the Student: ");
        String name = sc.next();
        int roll = sc.nextInt();
        String branch = sc.next();
        student.initialize(name, roll, branch);
        System.out.println("The Student details are: ");
        student.display();
    }
}
