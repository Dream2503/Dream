#include <iostream>
using namespace std;

class Matrix {
    int *array, len;

    public:
        Matrix(int);
        ~Matrix() {delete []this->array;}
        void set(int i, int j, int value) {if (i >= j) this->array[(i*(i-1)/2)+j-1] = value;}
        int get(int, int);
        void display();    
};
Matrix::Matrix(int size) {
    this->array = new int[size*(size-1)/2];
    this->len = size;
}
int Matrix::get(int i, int j) {
    if (i >= j) return this->array[(i*(i-1)/2)+j-1];
    else return 0;
}
void Matrix::display() {
    for (int i = 1; i <= this->len; i++) {
        for (int j = 1; j <= this->len; j++) {
            if (i >= j) cout << this->array[(i*(i-1)/2)+j-1] << " ";
            else cout << "0 ";
        }
        cout << endl;;
    }
}

int main() {
    int size, value;
    cout << "Enter dimension of the matrix: ";
    cin >> size;
    Matrix matrix(size);
    cout << "Enter all elements:" << endl;

    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++) {
            cin >> value;
            matrix.set(i, j, value);
        }
    cout << endl << endl;
    matrix.display();
    return 0;
}