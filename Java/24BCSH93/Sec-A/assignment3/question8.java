/*	Q8. Develop a java program that will deal with employee information of an organization. Define a class Employee, which has the data members and
        member functions are follows.
        Data Members :- employeeName , employeeNumber, basicSalary, DA, HRA
        Member Functions :- calculateGrossSalary(), showEmployeeDetails()
        Define default constructor
        Define parameterized constructor
        Create an array of objects. Display those employees, whose gross salary is more than 50,000. Note: You are free to add more number of
        relevant data member and member function.
*/

import java.util.Scanner;

class Employee {
    private int employeeNumber;
    private String employeeName;
    private double basicSalary, DA, HRA;

    public Employee() {
        this.employeeNumber = 0;
        this.employeeName = "Unknown";
        this.basicSalary = 0.0;
        this.DA = 0.0;
        this.HRA = 0.0;
    }

    public Employee(int employeeNumber, String employeeName, double basicSalary, double DA, double HRA) {
        this.employeeNumber = employeeNumber;
        this.employeeName = employeeName;
        this.basicSalary = basicSalary;
        this.DA = DA;
        this.HRA = HRA;
    }

    public double calculateGrossSalary() {
        return basicSalary + DA + HRA;
    }

    public void displayStudentDetails() {
        System.out.println("Employee Number: " + employeeNumber);
        System.out.println("Employee Name: " + employeeName);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("DA: " + DA);
        System.out.println("HRA: " + HRA);
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of employees you want to add: ");
        int size = sc.nextInt();
        Employee[] employees = new Employee[size];

        for (int i = 0; i < size; i++) {
            System.out.println("\nEnter the details of Employee" + (i + 1) + ":");
            System.out.print("Enter the Employee no.: ");
            int employeeNumber = sc.nextInt();
            System.out.print("Enter the Employee name: ");
            String employeeName = sc.next();
            System.out.print("Enter the basic salary: ");
            double basicSalary = sc.nextDouble();
            System.out.print("Enter the DA: ");
            double DA = sc.nextDouble();
            System.out.print("Enter the HRA: ");
            double HRA = sc.nextDouble();
            employees[i] = new Employee(employeeNumber, employeeName, basicSalary, DA, HRA);
        }
        System.out.println("The employees with gross salary more than 50,000 are:");

        for (Employee employee : employees) {
            if (employee.calculateGrossSalary() > 50000) {
                employee.displayStudentDetails();
            }
        }
    }
}
