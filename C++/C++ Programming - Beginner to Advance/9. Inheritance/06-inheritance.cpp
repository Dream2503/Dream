#include <iostream>
using namespace std;
class Employee {
    private:
        int eid;
        string name;

    public:
        Employee(int eid, string name) {
            this->eid = eid;
            this->name = name;
        }
        int getEmployeeID() {return this->eid;}
        string getName() {return this->name;}
};

class FulltimeEmployee: public Employee {
    private:
        int salary;
    public:
        FulltimeEmployee(int eid, string name, int salary): Employee(eid, name) {this->salary = salary;}
        int getSalary() {return this->salary;}
};

class PartTimeEmployee: public Employee {
    private:
        int wage;

    public:
        PartTimeEmployee(int eid, string name, int wage): Employee(eid, name) {this->wage = wage;}
        int getWage() {return this->wage;}
};

int main() {
    PartTimeEmployee p1(1, "John", 300);
    FulltimeEmployee p2(2, "Raj", 5000);

    cout << "Salary of " << p2.getName() << " is " << p2.getSalary() << endl;
    cout << "Daily wage of " << p1.getName() << " is " << p1.getWage() << endl;
    return 0;
}