#include <iostream>
using namespace std;

class Student {
    private:
        int roll, physics, chemistry, math;
        string name;

    public:
        Student(int roll, string name, int physics, int chemistry, int math);
        char grade();
        int total();
};
Student::Student(int roll, string name, int physics, int chemistry, int math) {
    this->roll = roll;
    this->name = name;
    this->physics = physics;
    this->chemistry = chemistry;
    this->math = math;
}
char Student::grade() {
    float average = this->total() / 3;

    if(average > 60)
        return 'A';
    else if(average >= 40 and average < 60)
        return 'B';
    else
        return 'C';
}
int Student::total() {return this->physics + this->chemistry+this-> math;}

int main() {
    int roll, physics, chemistry, math;
    string name;
    cout << "Enter Roll number of a Student: ";
    cin >> roll;
    cout << "Enter Name of a Student: ";
    cin >> name;
    cout << "Enter marks in 3 subjects: ";
    cin >> physics >> chemistry >> math;
    Student stud(roll, name, physics, chemistry, math);
    cout << "Total Marks: " << stud.total() << endl;
    cout << "Grade of Student: " << stud.grade() << endl;
}