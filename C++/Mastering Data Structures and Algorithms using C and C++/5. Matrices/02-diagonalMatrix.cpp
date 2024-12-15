#include <iostream>
using namespace std;

class Matrix {
    int *array, len;

    public:
        Matrix(int);
        ~Matrix() {delete []this->array;}
        void set(int i, int j, int value) {if (i == j) this->array[i-1] = value;}
        int get(int, int);
        void display();    
};
Matrix::Matrix(int size) {
    this->array = new int[size];
    this->len = size;
}
int Matrix::get(int i, int j) {
    if (i == j) return this->array[i-1];
    else return 0;
}
void Matrix::display() {
    for (int i = 0; i < this->len; i++) {
        for (int j = 0; j < this->len; j++) {
            if (i == j) cout << this->array[i] << " ";
            else cout << "0 ";
        }
        cout << endl;;
    }
}

int main() {
    Matrix matrix(4);
    matrix.set(1, 1, 5);
    matrix.set(2, 2, 8);
    matrix.set(3, 3, 9);
    matrix.set(4, 4, 12);
    cout << matrix.get(2, 2) << endl;
    matrix.display();
    return 0;
}