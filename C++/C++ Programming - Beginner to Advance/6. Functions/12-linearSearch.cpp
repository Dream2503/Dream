#include<iostream>
using namespace std;

int search(int *array, int len, int key) {
    for (int i = 0; i < len; i++)
        if (key == array[i])
            return i;

    return -1;
}

int main() {
    int list[] = {2, 4, 5, 7, 10, 9, 13}, key;
    cout << "Enter an Element to be Searched: ";
    cin >> key;
    int index = search(list, 7, key);
    cout << "Element found at index : " << index << endl;
    return 0;
}