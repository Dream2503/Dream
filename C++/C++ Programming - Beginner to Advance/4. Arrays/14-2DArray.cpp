#include <iostream>
using namespace std;

int main() {
    int array[2][3] = {{2, 4, 6}, {3, 6, 9}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            cout << array[i][j] << ' ';
        
        cout << endl;
    }
    return 0;
}