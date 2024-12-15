#include<iostream>
using namespace std;

int main() {
    float radius, area;
    cout << "Enter radius of a circle: ";
    cin >> radius;
    area = 3.14159 * radius * radius;
    cout << "Area of a Circle is " << area << endl;
    return 0;
}