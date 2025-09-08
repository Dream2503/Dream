/*	Q5. Write a program to declare a class employee with data members id, name, department, salary. Add a method getData(), putData() to accept and
        display the details of n employees. Define a Main class to create the objects of employee class and perform basic operations.
*/

import java.util.Scanner;

class Employee {
    private int id;
    private String name, department;
    private double salary;

    public void putData(int id, String name, String department, double salary) {
        if (id <= 0) {
            System.out.println("Employee ID can only be positive");
            System.exit(0);
        }
        if (salary < 0.0) {
            System.out.println("Salary cannot be negative");
            System.exit(0);
        }
        this.id = id;
        this.name = name;
        this.department = department;
        this.salary = salary;
    }

    public void getData() {
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
        System.out.println("Salary: " + salary);
        System.out.println();
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
            employees[i] = new Employee();
            System.out.print("Enter the Employee ID, Name, Department and Salary of Employee" + (i + 1) + ": ");
            int id = sc.nextInt();
            String name = sc.next();
            String department = sc.next();
            double salary = sc.nextDouble();
            employees[i].putData(id, name, department, salary);
        }
        System.out.println("\nThe employee data are: ");

        for (Employee employee : employees) {
            employee.getData();
        }
    }
}
