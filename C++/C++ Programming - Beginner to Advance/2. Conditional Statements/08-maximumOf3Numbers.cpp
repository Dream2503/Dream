#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter a number: ";
    cin >> b;
    cout << "Enter a number: ";
    cin >> c;

    if(a > b and a > c)
        cout << a;
    else if (b > c)
        cout << b;
    else
        cout << c;

    return 0;
}