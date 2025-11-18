/*  Q7. Create a class Person that has data member name. Use constructor to initialize name and display() to display name. Create a derived class
        Employee from Person class having private members id. Using constructor initialize id and have method display() to display id. Create another
        derived class HourlyEmployee from Employee with private members hourlyRate and hoursWorked. Use constructor to initialize input and methods
        getGrossPay() that computes and returns the gross pay of the employee and display() to display the hourlyRate, hoursWorked and gross pay.
        Create a Main class to test the functionalities of the above classes and display output in the following format
        Name: John Smith
        ID: 7569
        Hourly Rate: 100
        Hours Worked: 2000
        Gross pay: 200000
*/

import java.util.Scanner;

class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public void display() {
        System.out.println("Name: " + name);
    }
}

class Employee extends Person {
    private int id;

    public Employee(String name, int id) {
        super(name);
        validate("ID", id);
        this.id = id;
    }

    protected static void validate(String name, double value) {
        if (value <= 0.0) {
            System.out.println(name + " can only be positive");
            System.exit(0);
        }
    }

    public void display() {
        super.display();
        System.out.println("ID: " + id);
    }
}

class HourlyEmployee extends Employee {
    private double hourlyRate;
    private int hoursWorked;

    public HourlyEmployee(String name, int id, double hourlyRate, int hoursWorked) {
        super(name, id);
        validate("Hourly Rate", hourlyRate);
        validate("Hours Worked", hoursWorked);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    public double getGrossPay() {
        return hoursWorked * hourlyRate;
    }

    public void display() {
        super.display();
        System.out.println("Hourly Rate: " + hourlyRate);
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Gross Pay: " + getGrossPay());
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Name of the Person: ");
        String name = sc.nextLine();

        Person person = new Person(name);
        person.display();
        System.out.print("\nEnter ID of the Employee: ");
        int id = sc.nextInt();

        person = new Employee(name, id);
        person.display();

        System.out.print("\nEnter the Hourly Rate of the HourlyEmployee: ");
        double hourlyRate = sc.nextDouble();
        System.out.print("Enter the Hours Worked of the HourlyEmployee: ");
        int hoursWorked = sc.nextInt();

        person = new HourlyEmployee(name, id, hourlyRate, hoursWorked);
        person.display();
    }
}
