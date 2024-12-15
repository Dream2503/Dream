#include <iostream>
using namespace std;

int main() {
    int num, res = 0;
    cout << "Enter a number: ";
    cin >> num;

    while (num > 0) {
        res = (res * 10) +(num % 10);
        num /= 10;
    }
    cout << "Reversed number is " << res;
    return 0;
}