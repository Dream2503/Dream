#include <iostream>
using namespace std;

int main() {
    float principalAmount, rateOfInterest, timePeriod;
    cout << "Enter the principal amount: ";
    cin >> principalAmount;
    cout << "Enter the rate of interest: ";
    cin >> rateOfInterest;
    cout << "Enter the time period: ";
    cin >> timePeriod;
    cout << "The simple interest is " << principalAmount * rateOfInterest * timePeriod / 100;
    return 0;
}
