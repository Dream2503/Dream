/*  Q3. Write a Java program that defines a class Employee and displays employee details using two overloaded methods.
        •	If the employee is a general employee, the program should invoke one method to display the details.
        •	If the employee is a manager, it should invoke the other overloaded method to display the details differently.
*/

import java.util.Scanner;

class Employee {
    private int number;
    private String name;
    private double basicSalary, DA, HRA;

    public Employee(int number, String name, double basicSalary, double DA, double HRA) {
        if (number <= 0) {
            System.out.println("Employee Number can only be positive");
            System.exit(0);
        }
        validate(basicSalary, "Basic Salary");
        validate(DA, "DA");
        validate(HRA, "HRA");
        this.number = number;
        this.name = name;
        this.basicSalary = basicSalary;
        this.DA = DA;
        this.HRA = HRA;
    }

    public void display() {
        System.out.println("Employee Number: " + number);
        System.out.println("Employee Name: " + name);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("DA: " + DA);
        System.out.println("HRA: " + HRA);
        System.out.println();
    }

    public void display(String department) {
        System.out.println("Manager Number: " + number);
        System.out.println("Manager Name: " + name);
        System.out.println("Department: " + department);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("DA: " + DA);
        System.out.println("HRA: " + HRA);
        System.out.println();
    }

    private static void validate(double value, String name) {
        if (value < 0.0) {
            System.out.println(name + " cannot be negative");
            System.exit(0);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Employee employee1 = createEmployee("first");
        Employee employee2 = createEmployee("second");
        System.out.println("Enter the department of the second employee: ");
        String department = sc.next();
        System.out.print("The details of the first employee: ");
        employee1.display();
        System.out.println("The details of the second employee (Manager): ");
        employee2.display(department);
    }

    private static Employee createEmployee(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Employee no., Name, Basic Salary, DA, HRA of " + name + " Employee: ");
        int employeeNumber = sc.nextInt();
        String employeeName = sc.next();
        double basicSalary = sc.nextDouble();
        double DA = sc.nextDouble();
        double HRA = sc.nextDouble();
        return new Employee(employeeNumber, employeeName, basicSalary, DA, HRA);
    }
}