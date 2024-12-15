#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, min = A[1];

    for (int x: A)
        if (min > x)
            min = x;

    cout << "Minimum value is " << min; 
    return 0;
}