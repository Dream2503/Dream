#include <iostream>
using namespace std;

int main() {
    int num, cnt = 0;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            cnt++;
    
    if (cnt)
        cout << num << " is not a prime number";
    else
        cout << num << " is a prime number";

    return 0;
}