/*	Q8. Develop a java program that will deal with employee information of an organization. Define a class Employee, which has the data members and
        member functions are follows.
        Data Members :- name, number, basicSalary, DA, HRA
        Member Functions :- calculateGrossSalary(), display()
        Define default constructor
        Define parameterized constructor
        Create an array of objects. Display those employees, whose gross salary is more than 50,000. Note: You are free to add more number of
        relevant data member and member function.
*/

import java.util.Scanner;

class Employee {
    private int number;
    private String name;
    private double basicSalary, DA, HRA;

    public Employee() {
        this.number = 0;
        this.name = "Unknown";
        this.basicSalary = 0.0;
        this.DA = 0.0;
        this.HRA = 0.0;
    }

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

    public double calculateGrossSalary() {
        return basicSalary + DA + HRA;
    }

    public void display() {
        System.out.println("Employee Number: " + number);
        System.out.println("Employee Name: " + name);
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
        System.out.print("Enter the number of Employee details you want to add: ");
        int size = sc.nextInt();
        Employee[] employees = new Employee[size];
        System.out.println("\nEnter the details of " + size + " Employees:");

        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Employee no., Name, Basic Salary, DA, HRA of Employee" + (i + 1) + ": ");
            int employeeNumber = sc.nextInt();
            String employeeName = sc.next();
            double basicSalary = sc.nextDouble();
            double DA = sc.nextDouble();
            double HRA = sc.nextDouble();
            employees[i] = new Employee(employeeNumber, employeeName, basicSalary, DA, HRA);
        }
        System.out.println("\nThe Employees with gross salary more than 50,000 are:");

        for (Employee employee : employees) {
            if (employee.calculateGrossSalary() > 50000) {
                employee.display();
            }
        }
    }
}
