/*	Q5. Write a java program that will create class BankAccount.
        Data Members :- number, name, balance, type
        Member Functions :- withdraw(), deposit(), display()
        Define default constructor
        Define parameterized constructor
        Define a Main class that accesses all members of the class.
*/

import java.util.Scanner;

class BankAccount {
    private int number;
    private String name, type;
    private double balance;

    public BankAccount() {
        this.number = 0;
        this.name = "Unknown";
        this.type = "savings";
        this.balance = 0.0;
    }

    public BankAccount(int number, String name, String type, double balance) {
        validate(number, "Account Number");
        validate(balance, "Account Balance");
        this.number = number;
        this.name = name;
        this.type = type;
        this.balance = balance;
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Insufficient Funds");
        } else {
            balance -= amount;
        }
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void display() {
        System.out.println("Account Number: " + number);
        System.out.println("Account Name: " + name);
        System.out.println("Account Type: " + type);
        System.out.println("Account Balance: " + balance);
        System.out.println();
    }

    private static void validate(double value, String name) {
        if (value < 0) {
            System.out.println(name + " cannot be negative");
            System.exit(0);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Account Number, Name, Type, Balance of your Bank Account: ");
        int number = sc.nextInt();
        String name = sc.next();
        String type = sc.next();
        double balance = sc.nextDouble();
        BankAccount bankAccount = new BankAccount(number, name, type, balance);
        BankAccount defaultAccount = new BankAccount();

        System.out.println("\nYour account details are: ");
        bankAccount.display();
        System.out.println("A default account details are: ");
        defaultAccount.display();

        System.out.println("Enter the amount you want to deposit into the default account: ");
        double depositAmount = sc.nextDouble();
        defaultAccount.deposit(depositAmount);
        System.out.println("Enter the amount you want to withdraw from your account: ");
        double withdrawAmount = sc.nextDouble();
        bankAccount.withdraw(withdrawAmount);

        System.out.println("\nYour account details after withdraw are: ");
        bankAccount.display();
        System.out.println("The default account details after deposit are: ");
        defaultAccount.display();
    }
}
