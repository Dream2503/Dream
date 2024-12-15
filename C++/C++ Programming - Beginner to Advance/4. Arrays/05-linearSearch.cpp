#include <iostream>
using namespace std;

int main() {
    int array[10], n = 10, key;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter #" << i + 1 << " element: ";
        cin >> array[i];
    }
    cout << "Enter the key: ";
    cin >> key;
    
    for (int i = 0; i < n; i++) {
        if (array[i] == key) {
            cout << "Key found at " << i;
            return 0;
        }
    }
    cout << "Key was not found";
    return 0;
}