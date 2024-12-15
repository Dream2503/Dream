#include <iostream>
using namespace std;

int main() {
    int hour;
    cout << "Enter the hour: ";
    cin >> hour;
    
    if (hour >= 10 and hour <= 18)
        cout << "Working hours";
    else
        cout << "Not working hours";
}