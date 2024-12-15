#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Enter a number x: ";
    cin >> x;
    cout << "Enter a number y: ";
    cin >> y;

    if (x > y)
        cout << "x is the greater number that is " << x;
    else
        cout << "y is the greater number that is " << y;
        
    return 0;
}