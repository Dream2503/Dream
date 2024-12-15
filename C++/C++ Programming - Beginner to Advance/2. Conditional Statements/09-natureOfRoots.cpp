#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, b, c, determinant;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;
    determinant = (b * b) - (4 * a * c);

    if (not determinant)
        cout << "This quadratic equation has only one solution ie " << -b / (2*a);
    else if (determinant > 0) {
        cout << "This quadratic equation has two solution \nroot1 - " << (-b + sqrt(determinant)) / (2 * a);
        cout << "\nroot2 - " << (-b - sqrt(determinant)) / (2 * a);
    } else
        cout << "This quadratic equation no real";
}