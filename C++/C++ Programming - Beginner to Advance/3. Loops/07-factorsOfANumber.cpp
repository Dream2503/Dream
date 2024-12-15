#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factors of " << num << " are -> 1, ";

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            cout << i << ", ";
    
    cout << num;
    return 0;
}