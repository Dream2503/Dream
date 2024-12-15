#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length, breadth;

    public:
        Rectangle(int length = 0, int breadth = 0);
        Rectangle(Rectangle &r);
        int getLength();
        int getBreadth();
        void setLength(int length);
        void setBreadth(int breadth);
        int area();
        int perimeter();
        bool isSquare();
        ~Rectangle();
};
Rectangle::Rectangle(int length = 0, int breadth = 0) {
    this->length = length;
    this->breadth = breadth;
}
Rectangle::Rectangle(Rectangle &r) {
    this->length = r.length;
    this->breadth = r.breadth;
}
    int Rectangle::getLength() {return this->length;}
    int Rectangle::getBreadth() {return this->breadth;}
    void Rectangle::setLength(int length) {this->length = length;}
    void Rectangle::setBreadth(int breadth) {this->breadth = breadth;}
    int Rectangle::area() {return this->length * this->breadth;}
    int Rectangle::perimeter() {return 2 * (this->length + this->breadth);}
    bool Rectangle::isSquare() {return this->length == this->breadth;}
    Rectangle::~Rectangle() {cout << "Rectangle Destroyed";}

int main() {
    Rectangle r1(10,10);
    cout << "Area " << r1.area() << endl;

    if (r1.isSquare())
        cout << "Yes"<<endl;
}