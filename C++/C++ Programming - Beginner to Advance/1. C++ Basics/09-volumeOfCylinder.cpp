#include <iostream>
using namespace std;

int main() {
    float radius, height;
    cout << "Enter the radius of the cylinder: ";
    cin >> radius;
    cout << "Enter the height of the cylinder: ";
    cin >> height;
    cout << "Volume of the cylinder is " << 3.14159 * radius * radius * height;
    return 0;
}