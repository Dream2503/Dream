#include <iostream>
using namespace std;

int main() {
    int num, temp, res = 0;
    cout << "Enter a number: ";
    cin >> num;
    temp = num;

    while (temp > 0) {
        res = (res * 10) +(temp % 10);
        temp /= 10;
    }
    if (res == num)
        cout << num << " is a palindrome";
    else
        cout << num << " is not a palindrome";
        
    return 0;
}