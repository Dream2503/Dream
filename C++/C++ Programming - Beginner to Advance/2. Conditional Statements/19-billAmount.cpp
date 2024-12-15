#include <iostream>
using namespace std;

int main() {
    float billAmount, discount = 0;

    cout << "Enter Bill Amount: ";
    cin >> billAmount;

    if (billAmount >= 500)
        discount = billAmount * 0.2;
    else if (billAmount >= 100 and billAmount < 500)
        discount = billAmount * 0.1;

    cout << "Bill Amount is: " << billAmount << endl;
    cout << "Discount is :" << discount << endl;
    cout << "Discounted Amount is: " << billAmount - discount << endl;
}