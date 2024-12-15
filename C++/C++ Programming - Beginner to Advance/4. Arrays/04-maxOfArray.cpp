#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, max = A[1];

    for (int x: A)
        if (max < x)
            max = x;

    cout << "Maximum value is " << max; 
    return 0;
}