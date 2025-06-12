#include <iostream>
using namespace std;

class Array {
    int *A;
    int size;
    int length;

public:
    Array(int size) {
        this->size = size;
        A = new int [size];
    }

    void create() {
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++) {
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }

    void display() {
        int i;

        for (i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
    }

    ~Array() {
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main() {
    Array arr(10);
    arr.create();
    arr.display();
    return 0;
}
