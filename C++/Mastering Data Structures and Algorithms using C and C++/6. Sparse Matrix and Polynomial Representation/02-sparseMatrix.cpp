#include <iostream>
using namespace std;

class Element {public: int i, j, value;};

class Sparse {
    int m, n, size;
    Element *array;
    
    public:
    Sparse(int, int, int); 
    ~Sparse() {delete []this->array;}
    Sparse operator+(Sparse&);
    friend istream &operator>>(istream&, Sparse&);
    friend ostream &operator<<(ostream&, Sparse&);


};
Sparse::Sparse(int m, int n, int size) {
    this->m = m;
    this->n = n;
    this->size = size;
    this->array = new Element[this->size];
}
Sparse Sparse::operator+(Sparse &matrix) {
    int i = 0, j = 0, k = 0;
    if (this->m != matrix.m or this->n != matrix.n) return Sparse(0, 0, 0);
    Sparse *sum = new Sparse(this->m, this->n, this->size+matrix.size);

    while (i < this->size and j < matrix.size) {
        if (array[i].i < matrix.array[j].i) sum->array[k++] = array[i++];
        else if (array[i].i > matrix.array[j].i) sum->array[k++] = matrix.array[j++];
        else {
            if (array[i].j < matrix.array[j].j) sum->array[k++] = array[i++];
            else if (array[i].j > matrix.array[j].j) sum->array[k++] = matrix.array[j++];
            else {
                sum->array[k] = array[i];
                sum->array[k++].value = array[i++].value + matrix.array[j++].value;
            }
        }
    }
    for (; i < this->size; i++) sum->array[k++] = array[i];
    for (; j < matrix.size; j++) sum->array[k++] = matrix.array[j];
    sum->size = k;
    return *sum;
}

istream &operator>>(istream &is, Sparse &matrix) {
    cout << "Enter non-zero elements";
    for (int i = 0; i < matrix.size; i++) cin >> matrix.array[i].i >> matrix.array[i].j >> matrix.array[i].value;
    return is;
}
ostream &operator<<(ostream &os, Sparse &matrix) {
    int k = 0;

    for (int i = 0; i < matrix.m; i++) {
        for (int j = 0; j < matrix.n; j++) {
            if (matrix.array[k].i == i and matrix.array[k].j == j) cout << matrix.array[k++].value << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return os;
}

int main() {
    Sparse matrix1(5, 5, 5);
    Sparse matrix2(5, 5, 5);
    cin >> matrix1;
    cin >> matrix2;
    Sparse sum = matrix1 + matrix2;
    cout << "First Matrix" << endl << matrix1;
    cout << "Second Matrix" << endl << matrix2;
    cout << "Sum Matrix" << endl << sum;
    return 0;
}