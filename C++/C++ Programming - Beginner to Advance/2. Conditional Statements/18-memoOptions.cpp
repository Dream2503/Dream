#include <iostream>
using namespace std;

int main() {
    cout << "Menu\n" << "1. Add\n" << "2. Sub\n" << "3. Mul\n" << "4. Div\n\n";
    int a, b, c, option;
    cout << "Enter your choice no: ";
    cin >> option;
    cout << "Enter two numbers: "; 
    cin >> a >> b;

    switch (option) {
        case 1: 
            c = a + b;
            break;
        case 2:
            c = a - b;
            break;
        case 3:
            c = a * b;
            break;
        case 4:
            c = a / b;
            break;
    }
    cout << c;
    return 0;
}