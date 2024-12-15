#include<iostream>
using namespace std;

int main()
{
    float basic, percentAllow, percentDeduct, netSalary;
    cout << "Enter Basic Salary: ";
    cin >> basic;
    cout << "Enter percent of Allowances: ";
    cin >> percentAllow;
    cout << "Enter percent of Deductions: ";
    cin >> percentDeduct;
    netSalary = basic + basic * percentAllow / 100 - basic * percentDeduct / 100;
    cout << "Net Salary is: " << netSalary << endl;
}