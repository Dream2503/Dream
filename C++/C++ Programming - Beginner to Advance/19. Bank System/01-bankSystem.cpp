#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;
#define MIN_BALANCE 500

class InsufficientFunds{};

class Account {
    private:
        long accountNumber;
        string firstName;
        string lastName;
        float balance;
        static long NextAccountNumber;

    public:
        Account() {}
        Account(string firstName, string lastName, float balance);
        long getAccNo() {return accountNumber;}
        string getFirstName() {return firstName;}
        string getLastName() {return lastName;}
        float getBalance() {return balance;}
        void Deposit(float amount);
        void Withdraw(float amount);
        static void setLastAccountNumber(long accountNumber);
        static long getLastAccountNumber();
        friend ofstream &operator<<(ofstream &file, Account &account);
        friend ifstream &operator>>(ifstream &log, Account &account);
        friend ostream &operator<<(ostream &out, Account &account);
};

long Account::NextAccountNumber = 0;

Account::Account(string firstName, string lastName, float balance) {
    NextAccountNumber++;
    this->accountNumber = NextAccountNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->balance = balance;
}
void Account::Deposit(float amount) {
    this->balance += amount;
}
void Account::Withdraw(float amount) {
    if(this->balance - amount < MIN_BALANCE)
        throw InsufficientFunds();
        this->balance -= amount;
}
void Account::setLastAccountNumber(long accountNumber) {
    NextAccountNumber = accountNumber;
}
long Account::getLastAccountNumber() {
    return NextAccountNumber;
}
ofstream & operator<<(ofstream &file, Account &account) {
    file << account.accountNumber << endl;
    file << account.firstName << endl;
    file << account.lastName << endl;
    file << account.balance << endl;
    return file;
}
ifstream & operator>>(ifstream &log ,Account &account) {
    log >> account.accountNumber;
    log >> account.firstName;
    log >> account.lastName;
    log >> account.balance;
    return log;
}
ostream & operator<<(ostream &out, Account &account) {
    out << "First Name: " << account.getFirstName() << endl;
    out << "Last Name: " << account.getLastName() << endl;
    out << "Account Number: " << account.getAccNo() << endl;
    out << "Balance: " << account.getBalance() << endl;
    return out;
}

class Bank {
    private:
        map <long, Account> accounts;

    public:
        Bank();
        Account OpenAccount(string firstName, string lastName, float balance);
        Account BalanceEnquiry(long accountNumber);
        Account Deposit(long accountNumber, float amount);
        Account Withdraw(long accountNumber, float amount);
        void CloseAccount(long accountNumber);
        void ShowAllAccounts();
        ~Bank();
};

Bank::Bank() {
    Account account;
    ifstream infile("Bank.data");

    if(!infile) {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    while(!infile.eof()) {
        infile >> account;
        accounts.insert(pair <long, Account>(account.getAccNo(), account));
    }
    Account::setLastAccountNumber(account.getAccNo());
    infile.close();
}
Account Bank::OpenAccount(string firstName, string lastName, float balance) {
    ofstream outfile;
    Account account(firstName, lastName, balance);
    accounts.insert(pair <long, Account>(account.getAccNo(), account));
    outfile.open("Bank.data", ios::trunc);
    map <long, Account>::iterator itr;

    for(itr = accounts.begin(); itr != accounts.end(); itr++)
        outfile << itr->second;

    outfile.close();
    return account;
}
Account Bank::BalanceEnquiry(long accountNumber) {
    map <long, Account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}
Account Bank::Deposit(long accountNumber, float amount) {
    map <long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}
Account Bank::Withdraw(long accountNumber, float amount) {
    map <long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}
void Bank::CloseAccount(long accountNumber) {
    map <long, Account>::iterator itr = accounts.find(accountNumber);
    cout << "Account Deleted" << itr->second;
    accounts.erase(accountNumber);
}
void Bank::ShowAllAccounts() {
    map <long,Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++) {
        cout << "Account " << itr->first << endl << itr->second <<endl;
    }
}
Bank::~Bank() {
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);
    map <long, Account>::iterator itr;

    for (itr = accounts.begin(); itr != accounts.end(); itr++)
        outfile << itr->second;

    outfile.close();
}

int main() {
    Bank b;
    Account account;
    int choice;
    string firstName,lastName;
    long accountNumber;
    float balance, amount;

    cout << "***Banking System***" << endl;
    
    do {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Open an Account";
        cout << "\n\t2 Balance Enquiry";
        cout << "\n\t3 Deposit";
        cout << "\n\t4 Withdrawal";
        cout << "\n\t5 Close an Account";
        cout << "\n\t6 Show All Accounts";
        cout << "\n\t7 Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter inital Balance: ";
                cin >> balance;
                account = b.OpenAccount(firstName, lastName, balance);
                cout << endl << "Congratulation Account is Created" << endl;
                cout << account;
                break;
                
            case 2:
                cout << "Enter Account Number:";
                cin >> accountNumber;
                account = b.BalanceEnquiry(accountNumber);
                cout << endl << "Your Account Details" << endl;
                cout << account;
                break;

            case 3:
                cout << "Enter Account Number:";
                cin >> accountNumber;
                cout << "Enter Balance:";
                cin >> amount;
                account = b.Deposit(accountNumber, amount);
                cout << endl<<"Amount is Deposited" << endl;
                cout << account;
                break;

            case 4:
                cout << "Enter Account Number:";
                cin >> accountNumber;
                cout << "Enter Balance:";
                cin >> amount;
                account = b.Withdraw(accountNumber, amount);
                cout << endl << "Amount Withdrawn" << endl;
                cout << account;
                break;

            case 5:
                cout << "Enter Account Number:";
                cin >> accountNumber;
                b.CloseAccount(accountNumber);
                cout << endl << "Account is Closed" << endl;
                cout << account;

            case 6:
                b.ShowAllAccounts();
                break;

            case 7:
                break;

            default:
                cout << endl << "Enter correct choice";
                exit(0);
        }
    } while (choice != 7);
    
    return 0;
}