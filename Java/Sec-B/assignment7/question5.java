/*  Q5. Write a class called Account with the following properties and methods:
        Properties: String name, int accountNo, double balance
	    Methods: void deposit(double amount)
                 void withdraw(double amount)
                 void transfer(Account account1, Account account1, double amount)
        Assume that an account needs to have a minimum balance of 500. If an attempt is made to withdraw or transfer, which results in balance going
        below 500, throw a user defined exception called MinimumBalanceException. Use throw and throws wherever necessary.
*/

import java.util.Scanner;

class NonPositiveValueException extends Exception {
    String name;
    double value;

    public NonPositiveValueException(String name, double value) {
        this.name = name;
        this.value = value;
    }

    public String toString() {
        return name + " must be a positive value. " + value + " was provided";
    }
}

class MinimumBalanceException extends Exception {
    double balance;

    public MinimumBalanceException(double balance) {
        this.balance = balance;
    }

    public String toString() {
        return "Remaining balance after transaction would be " + balance + ". Minimum Balance Required is " + Account.MIN_BALANCE;
    }
}

class Account {
    public static final double MIN_BALANCE = 500.0;
    private String name;
    private int accountNo;
    private double balance;

    public Account(String name, int accountNo, double balance) throws NonPositiveValueException, MinimumBalanceException {
        if (accountNo <= 0) {
            throw new NonPositiveValueException("Account Number", accountNo);
        }
        if (balance <= 0) {
            throw new NonPositiveValueException("Initial Balance", balance);
        }
        if (balance < MIN_BALANCE) {
            throw new MinimumBalanceException(balance);
        }
        this.name = name;
        this.accountNo = accountNo;
        this.balance = balance;
    }

    public void deposit(double amount) throws NonPositiveValueException {
        if (amount <= 0) {
            throw new NonPositiveValueException("Deposit Amount", amount);
        }
        balance += amount;
    }

    public void withdraw(double amount) throws NonPositiveValueException, MinimumBalanceException {
        if (amount <= 0) {
            throw new NonPositiveValueException("Withdrawal Amount", amount);
        }
        if (balance - amount < MIN_BALANCE) {
            throw new MinimumBalanceException(balance - amount);
        }
        balance -= amount;
    }

    public static void transfer(Account account1, Account account2, double amount) throws NonPositiveValueException, MinimumBalanceException {
        account1.withdraw(amount);
        account2.deposit(amount);
    }

    public String toString() {
        return "Account no.: " + accountNo + "\nName: " + name + "\nBalance: " + balance;
    }
}

class Main {
    public static void main(String[] args) throws NonPositiveValueException, MinimumBalanceException {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Name for Account1: ");
        String name1 = sc.next();
        System.out.print("Enter the Account number for Account1: ");
        int accountNo1 = sc.nextInt();
        System.out.print("Enter the Initial Balance for Account1: ");
        double balance1 = sc.nextDouble();
        Account account1 = new Account(name1, accountNo1, balance1);

        System.out.print("\nEnter the Name for Account2: ");
        String name2 = sc.next();
        System.out.print("Enter the Account number for Account2: ");
        int accountNo2 = sc.nextInt();
        System.out.print("Enter the Initial Balance for Account2: ");
        double balance2 = sc.nextDouble();
        Account account2 = new Account(name2, accountNo2, balance2);

        System.out.print("\nEnter the amount to deposit from Account1: ");
        double amount1 = sc.nextDouble();
        account1.deposit(amount1);
        System.out.println("Account details after deposit:\n" + account1);

        System.out.print("\nEnter the amount to withdraw from Account2: ");
        double amount2 = sc.nextDouble();
        account2.withdraw(amount2);
        System.out.println("Account details after withdraw:\n" + account2);

        System.out.print("\nEnter the amount to transfer from Account1 to Account2: ");
        double amount3 = sc.nextDouble();
        Account.transfer(account1, account2, amount3);
        System.out.println("Account details after transfer:\n" + account1 + "\n" + account2);
    }
}