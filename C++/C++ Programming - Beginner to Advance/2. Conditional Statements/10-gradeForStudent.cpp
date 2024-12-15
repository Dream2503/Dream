#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float m1, m2, m3, average;
    cout << "Enter the value of m1: ";
    cin >> m1;
    cout << "Enter the value of m2: ";
    cin >> m2;
    cout << "Enter the value of m3: ";
    cin >> m3;
    average = (m1 + m2 + m3) / 3;

    if (average >= 60)
        cout << 'A';
    else if (35 <= average < 60) {
        cout << 'B';
    } else
        cout << 'C';
}