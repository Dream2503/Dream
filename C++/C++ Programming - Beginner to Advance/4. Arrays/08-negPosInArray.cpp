#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, cntNeg = 0, cntPos = 0;

    for (int x: A) {
        if (x > 0)
            cntPos++;
        else if (x < 0)
            cntNeg++;
    }
    cout << "Total negative value is " << cntNeg << endl;
    cout << "Total positive value is " << cntPos; 
    return 0;
}