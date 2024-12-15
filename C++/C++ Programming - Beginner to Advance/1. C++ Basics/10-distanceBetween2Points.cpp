#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float x1, x2, y1, y2;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter y1: ";
    cin >> y1;
    cout << "Enter y1: ";
    cin >> y2;
    cout << "Distance between two points is " << sqrt(powf(x2 - x1, 2) + powf(y2 - y2, 2));
    return 0;
}
