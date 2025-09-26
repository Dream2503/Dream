/*  Q7.                                                             Mini Project
        Title: Develop Banking Application
        Requirement:
        BankAccount.java is the Super Class for Savings Account. This program was created to develop OOP skills, in particular - Inheritance and
        Abstraction. BankAccount.java has a deposit, withdrawal, updateInterest, and monthlyTotalAmount methods. It also has the setter/mutator
        method: setMonthlyFee, and the getter/accessor methods: getBalance, getNumberOfDeposits, getNumberOfWithdrawals, getInterestRate, and
        getMonthlyFee. BankAccount.java is an abstract class with the abstract methods withdraw, deposit, and monthlyTotal.

        Abstract classes can't be instantiated and BankAccount serves as a Superclass for the SavingsAccount Subclass. The SavingsAccount Subclass
        defines the above abstract methods and extends (inherits) the other properties and methods from BankAccount.
        Main.java provides a demo sample of how to utilize the bank program that has been created. In this file, a new object mySavingsAcc is created
        from its constructor. This takes the value of $10,000, 3% Annual Interest, and a $4 monthly fee. This will be the amount in the bank, the
        interest rate, and fees we will be working with.
        If more than 4 withdrawals are made per month, the fee will be increased by $1 per additional transaction. The program asks the user for
        withdrawals and deposits and displays the total amount in the bank account. It also outputs the number of deposits and withdrawals made.
        WARNING: monthlyTotal() calls super.monthlyTotalAmount(). This Subtracts monthly fee, adds interest. Resets monthly deposits and withdrawals
        to 0.
        Ensure that the monthlyTotal() is called after the deposits and withdrawals number has been output else it will be reset to 0.
        The program calculates the balance at the end of the month taking into consideration all deposits, withdrawals, fees, and interest.

        The following link can be used for your reference(Do not copy the code, write your own code).
            https://github.com/Jon-Peppinck/javaBankInheritAbstract
*/

import java.util.Scanner;

abstract class BankAccount {
    protected double balance, interestRate, monthlyFee;
    protected int depositsCount, withdrawalCount;

    public BankAccount(double balance, double interestRate, double monthlyFee) {
        validate(balance, "Balance");
        validate(interestRate, "Interest Rate");
        validate(monthlyFee, "Monthly Fee");
        this.balance = balance;
        this.interestRate = interestRate;
        this.monthlyFee = monthlyFee;
        depositsCount = withdrawalCount = 0;
    }

    public void deposit(double amount) {
        balance += amount;
        depositsCount++;
    }

    public void withdrawal(double amount) {
        if (balance < amount) {
            System.out.println("Insufficient Funds");
            return;
        }
        balance -= amount;
        withdrawalCount++;
    }

    public void updateInterest() {
        balance += balance * interestRate / 100 / 12;
    }

    public void monthlyTotalAmount() {
        balance -= monthlyFee;
        updateInterest();
        depositsCount = 0;
        withdrawalCount = 0;
    }

    public double getBalance() {
        return balance;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        validate(interestRate, "Interest Rate");
        this.interestRate = interestRate;
    }

    public double getMonthlyFee() {
        return monthlyFee;
    }

    public void setMonthlyFee(double monthlyFee) {
        validate(monthlyFee, "Monthly Fee");
        this.monthlyFee = monthlyFee;
    }

    public int getDepositsCount() {
        return depositsCount;
    }

    public int getWithdrawalCount() {
        return withdrawalCount;
    }

    private static void validate(double value, String name) {
        if (value < 0) {
            System.out.println(name + " cannot be negative");
            System.exit(0);
        }
    }

    public abstract void withdraw();
    public abstract void deposit();
    public abstract void monthlyTotal();
}

class SavingsAccount extends BankAccount {
    public SavingsAccount(double balance, double interestRate, double monthlyFee) {
        super(balance, interestRate, monthlyFee);
    }

    public void withdraw() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the amount to withdraw: $");
        double amount = sc.nextDouble();

        if (balance < amount) {
            System.out.print("Insufficient Funds");
        } else {
            withdrawal(amount);
        }
    }

    public void deposit() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the amount to deposit: $");
        double amount = sc.nextDouble();
        super.deposit(amount);
    }

    public void monthlyTotal() {
        monthlyFee += withdrawalCount > 4 ? withdrawalCount - 4 : 0;
        monthlyTotalAmount();
    }
}

class Main {
    public static void main(String[] args) {
        BankAccount mySavingsAcc = new SavingsAccount(10000, 3, 4);
        mySavingsAcc.withdraw();
        mySavingsAcc.withdraw();
        mySavingsAcc.withdraw();
        mySavingsAcc.withdraw();
        mySavingsAcc.withdraw();

        System.out.println("The balance is: $" + mySavingsAcc.getBalance());
        mySavingsAcc.deposit();
        System.out.println("The balance is: $" + mySavingsAcc.getBalance());
        System.out.println("The number of withdrawals this month is: " + mySavingsAcc.getWithdrawalCount());
        System.out.println("The number of deposits this month is: " + mySavingsAcc.getDepositsCount());

        mySavingsAcc.monthlyTotal();
        System.out.println("The monthly fee is: $" + mySavingsAcc.getMonthlyFee());
        System.out.println("The total balance (including fees and interest) this month is: $" + mySavingsAcc.getBalance());
    }
}
