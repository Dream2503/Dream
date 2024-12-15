#include <iostream>
using namespace std;

int main() {
    float distance, time;
    cout << "Enter a the distance traveled: ";
    cin >> distance;
    cout << "Enter a the total time taken: ";
    cin >> time;
    cout << "Total speed is " << distance / time;
    return 0;
}
