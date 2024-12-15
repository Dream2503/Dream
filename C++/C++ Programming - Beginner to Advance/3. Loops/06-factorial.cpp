#include <iostream>
using namespace std;

int main() {
    int num, fact = 1;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 2; i <= num; i++)
        fact *= i;
    
    cout << "Total sum is " << fact;
    return 0;
}