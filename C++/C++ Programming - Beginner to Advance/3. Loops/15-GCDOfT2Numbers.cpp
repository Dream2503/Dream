#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter a number: ";
    cin >> num2;

    while (num1 != num2) {
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    cout << "GCD of the 2 numbers are " << num1;
    return 0;
}