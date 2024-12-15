#include <iostream>
using namespace std;

int main() {
    int num, sum = 1;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            sum += i;
    
    if (2 * num == sum + num)
        cout << num << " is a perfect number";
    else
        cout << num << " is not a perfect number";

    return 0;
}