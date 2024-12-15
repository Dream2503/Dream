#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, sum = 0;

    for (int x: A)
        sum += x;

    cout << "Total sum is " << sum; 
    return 0;
}