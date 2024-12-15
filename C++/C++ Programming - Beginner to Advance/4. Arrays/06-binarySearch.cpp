#include <iostream>
using namespace std;

int main() {
    int array[] = {6, 8, 13, 17, 20, 22, 25, 28, 30, 35}, low = 0, high = 9, mid = 4, key;
    cout << "Enter the key: ";
    cin >> key;

    while (low <= high) {
        if (array[mid] > key)
            high = mid - 1;
        else if (array[mid] < key)
            low = mid + 1;
        else {
            cout << "Key found at " << mid;
            return 0;
        }
        mid = (low + high) / 2;
    }
    cout << "Key not found";
    return 0;
}