/*	Q1. Write a program that creates a class Account that have members accountNumber, customerName. Account has constructor to initialize its members
        and method display() to show the result. Create a child class SavingsAccount that is derived from Account class. SavingsAccount have members
        minBalance and savingBalance. Use show() to display its details. Then create another child class AccountDetails from SavingsAccount class have
        members deposit, withdraw and a method show1() to show its details. Child classes have constructors of their own. Create a Main class that
        creates a record of customer and display all its details.
*/

import java.util.Scanner;

class Account {
    private String accountNumber, customerName;

    public Account(String accountNumber, String customerName) {
        this.accountNumber = accountNumber;
        this.customerName = customerName;
    }

    public void display() {
        System.out.println("Account number: " + accountNumber);
        System.out.println("Customer Name: " + customerName);
    }

    protected static void validate(String name, double value) {
        if (value < 0) {
            System.out.println(name + " cannot be negative");
            System.exit(0);
        }
    }
}

class SavingsAccount extends Account {
    private double minBalance, savingBalance;

    public SavingsAccount(String accountNumber, String customerName, double minBalance, double savingBalance) {
        super(accountNumber, customerName);
        validate("Minimum Balance", minBalance);

        if (savingBalance < minBalance) {
            System.out.println("Saving Balance cannot be less than Minimum Balance");
        }
        this.minBalance = minBalance;
        this.savingBalance = savingBalance;
    }

    public void show() {
        display();
        System.out.println("Minimum Balance: " + minBalance);
        System.out.println("Saving Balance: " + savingBalance);
    }
}

class AccountDetails extends SavingsAccount {
    private double deposit, withdraw;

    public AccountDetails(String accountNumber, String name, double minBalance, double savingBalance, double deposit, double withdraw) {
        super(accountNumber, name, minBalance, savingBalance);
        validate("Deposit Amount", deposit);
        validate("Withdraw Amount", withdraw);
        this.deposit = deposit;
        this.withdraw = withdraw;
    }

    public void show1() {
        show();
        System.out.println("Deposit Amount: " + deposit);
        System.out.println("Withdraw Amount: " + withdraw);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Account Number of the customer: ");
        String accountNumber = sc.next();
        System.out.print("Enter the Customer Name of the customer: ");
        String name = sc.next();

        Account account = new Account(accountNumber, name);
        account.display();

        System.out.print("\nEnter the Minimum Balance of the Account: ");
        double minBalance = sc.nextDouble();
        System.out.print("Enter the Saving Balance of the Account: ");
        double savingBalance = sc.nextDouble();

        SavingsAccount savingsAccount = new SavingsAccount(accountNumber, name, minBalance, savingBalance);
        savingsAccount.show();

        System.out.print("\nEnter the Deposit Amount for the Account: ");
        double deposit = sc.nextDouble();
        System.out.print("Enter the Withdraw Amount for the Account: ");
        double withdraw = sc.nextDouble();

        AccountDetails accountDetails = new AccountDetails(accountNumber, name, minBalance, savingBalance, deposit, withdraw);
        accountDetails.show1();
    }
}
