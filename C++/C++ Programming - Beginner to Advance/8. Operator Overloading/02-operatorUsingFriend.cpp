#include <iostream>
using namespace std;

class Complex {
    private:
        int real, img;

    public:
        Complex(int real, int img);
        void display(); 
        friend Complex operator+(Complex c1, Complex c2);
};
Complex::Complex(int real = 0, int img = 0) {
    this->real = real;
    this->img = img;
}
Complex operator+(Complex c1, Complex c2) { 
    Complex res;
    res.real = c1.real + c2.real; 
    res.img = c1.img + c2.img;
    return res;
}
void Complex::display() {cout << this->real << "+i" << this->img << endl;}

int main() {
    Complex c1(5, 3), c2(10, 5), c3;
    c3 = c1 + c2;
    c3.display();
}