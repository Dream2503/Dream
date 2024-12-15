#include <iostream>
using namespace std;

int main() {
    int a[10][10], b[10][10], mult[10][10], row1, column1, row2, column2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> row1 >> column1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> row2 >> column2;

    if (column1 != row2) {
        cout << "Cant be Multiplied"; 
        return 0; 
    }
    cout << endl << "Enter elements of matrix 1:" << endl;
    
    for(int i = 0; i < row1; ++i)
        for(int j = 0; j < column1; ++j) {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    cout << endl << "Enter elements of matrix 2:" << endl;

    for(int i = 0; i < row2; ++i)
        for(int j = 0; j < column2; ++j) {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    for(int i = 0; i < row1; ++i)
        for(int j = 0; j < column2; ++j) { 
            mult[i][j]=0;
            
            for(int k = 0; k < column1; ++k)
                mult[i][j] += a[i][k] * b[k][j]; 
        }

    cout << endl << "Output Matrix: " << endl;

    for(int i = 0; i < row1; ++i)
        for(int j = 0; j < column2; ++j) {
            cout << " " << mult[i][j];

            if(j == column2-1)
                cout << endl;
        }

    return 0;
}