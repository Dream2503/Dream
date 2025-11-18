/*  Q1. Define a class Employee having basic data members Name, ID and BasicSalaray, with constructors and necessary member functions. Define a class
        Manager which is inherited from Employee class and having a data member bonus. Define the driver class that create object of the class
        Manager and access Manager details.
*/

import java.util.Scanner;

class Employee {
    protected int id;
    protected String name;
    protected double basicSalary;

    public Employee() {
        id = 0;
        name = "Unknown";
        basicSalary = 0.0;
    }

    public Employee(int id, String name, double basicSalary) {
        if (id <= 0) {
            System.out.println("Employee ID can only be positive");
            System.exit(0);
        }
        if (basicSalary < 0.0) {
            System.out.println("Salary cannot be negative");
            System.exit(0);
        }
        this.id = id;
        this.name = name;
        this.basicSalary = basicSalary;
    }

    public void display() {
        System.out.println("Employee ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Basic Salary: " + basicSalary);
    }
}

class Manager extends Employee {
    private double bonus;

    public Manager() {
        super();
        bonus = 0.0;
    }

    public Manager(int id, String name, double basicSalary, double bonus) {
        super(id, name, basicSalary);

        if (bonus < 0.0) {
            System.out.println("Salary cannot be negative");
            System.exit(0);
        }
        this.bonus = bonus;
    }

    public void display() {
        super.display();
        System.out.println("Bonus: " + bonus);
        System.out.println("Total Salary: " + (basicSalary + bonus));
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Employee ID: ");
        int employeeId = sc.nextInt();
        System.out.print("Enter Employee Name: ");
        String employeeName = sc.next();
        System.out.print("Enter Employee Basic Salary: ");
        double employeeSalary = sc.nextDouble();
        Employee employee = new Employee(employeeId, employeeName, employeeSalary);

        System.out.print("\nEnter Manager ID: ");
        int managerId = sc.nextInt();
        System.out.print("Enter Manager Name: ");
        String managerName = sc.next();
        System.out.print("Enter Manager Basic Salary: ");
        double managerSalary = sc.nextDouble();
        System.out.print("Enter Manager Bonus: ");
        double managerBonus = sc.nextDouble();
        Manager manager = new Manager(managerId, managerName, managerSalary, managerBonus);

        System.out.println("\nEmployee Details are:");
        employee.display();
        System.out.println("\nManager Details are:");
        manager.display();
    }
}
