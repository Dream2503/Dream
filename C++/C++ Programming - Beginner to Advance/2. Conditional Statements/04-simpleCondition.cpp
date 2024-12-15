#include <iostream>
using namespace std;

int main() {
    int roll;
    cout << "Enter your Roll No. " << endl;
    cin >> roll;

    if(roll > 0)
        cout << "Valid Roll No." << endl;
    else
        cout << "Invalid Roll No." << endl;
    
    return 0;
}