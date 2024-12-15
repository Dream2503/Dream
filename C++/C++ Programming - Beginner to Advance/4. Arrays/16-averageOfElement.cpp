#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the numbers of elements: ";
    cin >> n;
    float num[n], sum = 0;

    for(int i = 0; i < n; ++i) {
        cout << i + 1 << ". Enter number: ";
        cin >> num[i];
        sum += num[i];
    }
    cout << "Average = " << sum / n;

    return 0;
} 