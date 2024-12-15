#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, b, c, root1, root2;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;
    root1 = (-b + sqrtf(b*b- 4*a*c)) / (2 * a);
    root2 = (-b - sqrtf(b*b - 4*a*c)) / (2 * a);
    cout << "The first root of the quadratic equation is: " << root1;
    cout << "The first root of the quadratic equation is: " << root2;
}