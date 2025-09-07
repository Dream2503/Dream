/*	Q5. Write a java program that will create class BankAccount.
        Data Members :- accountNumber, accountHolderName, accountBalance, accountType
        Member Functions :- withdraw(), deposit(), displayAccountDetails()
        Define default constructor
        Define parameterized constructor
        Define a main class that accesses all members of the class.
*/

import java.util.Scanner;

class BankAccount {
    private int accountNumber;
    private String accountHolderName, accountType;
    private double accountBalance;

    public BankAccount() {
        this.accountNumber = 0;
        this.accountHolderName = "Unknown";
        this.accountType = "savings";
        this.accountBalance = 0.0;
    }

    public BankAccount(int accountNumber, String accountHolderName, String accountType, double accountBalance) {
        if (accountNumber < 0) {
            System.out.println("Account number can only be positive");
            System.exit(0);
        }
        if (accountBalance < 0.0) {
            System.out.println("Account Balance cannot be negative");
            System.out.println(0);
        }
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.accountType = accountType;
        this.accountBalance = accountBalance;
    }

    public void withdraw(double amount) {
        if (amount > accountBalance) {
            System.out.println("Insufficient Funds");
        } else {
            accountBalance -= amount;
        }
    }

    public void deposit(double amount) {
        accountBalance += amount;
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Holder Name: " + accountHolderName);
        System.out.println("Account Type: " + accountType);
        System.out.println("Account Balance: " + accountBalance);
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your bank details:");
        System.out.print("Your Account Number: ");
        int accountNumber = sc.nextInt();
        System.out.print("Your Name: ");
        String accountHolderName = sc.next();
        System.out.print("Your Account Type: ");
        String accountType = sc.next();
        System.out.print("Your Account Balance: ");
        double accountBalance = sc.nextDouble();
        BankAccount bankAccount = new BankAccount(accountNumber, accountHolderName, accountType, accountBalance);
        BankAccount defaultAccount = new BankAccount();

        System.out.println("\nYour account details are: ");
        bankAccount.displayAccountDetails();
        System.out.println("A default account details are: ");
        defaultAccount.displayAccountDetails();

        System.out.println("Enter the amount you want to deposit into default account: ");
        double depositAmount = sc.nextDouble();
        defaultAccount.deposit(depositAmount);

        System.out.println("Enter the amount you want to withdraw from your account: ");
        double withdrawAmount = sc.nextDouble();
        bankAccount.withdraw(withdrawAmount);

        System.out.println("\nYour account details after withdraw are: ");
        bankAccount.displayAccountDetails();
        System.out.println("The default account details after deposit are: ");
        defaultAccount.displayAccountDetails();
    }
}
