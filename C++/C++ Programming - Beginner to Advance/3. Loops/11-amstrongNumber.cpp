#include <iostream>
using namespace std;

int main() {
    int num, temp, res, sum = 0;
    cout << "Enter a number: ";
    cin >> num;
    temp = num;

    while (temp > 0) {
        res = temp % 10;
        sum += res * res * res;
        temp /= 10;
    }
    if (sum == num)
        cout << num << " is a Amstrong Number";
    else
        cout << num << " is not a Amstrong Number";

    return 0;
}