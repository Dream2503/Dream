#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <limits>
#include "..\C++\main\fraction"
using namespace std;

vector<vector<Fraction>> inputAugMatrix() {
    int row, column;
    string inputRow, fracStr;
    cout << "Enter the number of equations: ";
    cin >> row;
    cout << "Enter the number of variables: ";
    cin >> column;
    vector<vector<Fraction>> augMatrix(row, vector<Fraction>(++column));
    cin.ignore();

    for (int i = 0; i < row; i++) {
        cout << "Enter augmented row " << i + 1 << " (space-separated values): ";
        getline(cin, inputRow);
        stringstream ss(inputRow);

        for (int j = 0; j < column; j++) {
            ss >> fracStr;
            augMatrix[i][j] = Fraction(fracStr);
        }
    }
    return augMatrix;
}
vector<vector<Fraction>> echelonMatrix(vector<vector<Fraction>> &augMatrix) {
    int row = augMatrix.size();
    int column = augMatrix[0].size();
    int pivot = 0, cnt;

    while (pivot + 1 < row) {
        cnt = pivot;
        while (pivot < row and (double)augMatrix[pivot][cnt] == 0) pivot++;

        if (pivot == row) {
            cout << "The set of linear equations has no unique solution";
            exit(0);
        }
        if (pivot != cnt) swap(augMatrix[pivot], augMatrix[cnt]);
        pivot = cnt;

        for (int i = pivot + 1; i < row; i++) {
            Fraction factor = augMatrix[i][pivot] / augMatrix[pivot][pivot];
            for (int j = pivot; j < column; j++) augMatrix[i][j] -= factor * augMatrix[pivot][j];
        }
        pivot++;
    }
    return augMatrix;
}
vector<Fraction> gaussElimination(vector<vector<Fraction>>& echeMatrix) {
    int row = echeMatrix.size(), column = echeMatrix[0].size(), cnt;
    Fraction ans;

    if ((double)echeMatrix[row - 1][column - 2] != 0) {
        vector<Fraction> res;
        res.push_back(echeMatrix[row - 1][column - 1] / echeMatrix[row - 1][column - 2]);

        for (int i = row - 2; i >= 0; i--) {
            ans = cnt = 0;

            for (int j = column - 2; j > i; j--) {
                ans += echeMatrix[i][j] * res[cnt];
                cnt++;
            }
            res.push_back((echeMatrix[i][column - 1] - ans) / echeMatrix[i][i]);
        }
        reverse(res.begin(), res.end());
        return res;
    } else cout << "The set of linear equations has no unique solution";
    return {};
}

int main() {
    vector<vector<Fraction>> matrix = inputAugMatrix();
    vector<vector<Fraction>> echeMatrix = echelonMatrix(matrix);
    vector<Fraction> result = gaussElimination(echeMatrix);
    for (Fraction num: result) cout << num << " ";
    return 0;
}