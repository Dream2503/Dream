#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length, breadth;

    public:
        Rectangle() {};
        Rectangle(int length, int breadth);
        Rectangle(Rectangle &rectangle);
        int getLength() {return length;}
        int getBreadth() {return breadth;}
        void setLength(int length) {this->length = length;}
        void setBreadth(int breadth) {this->breadth = breadth;}
        int area() {return this->length * this->breadth;}
        int perimeter() {return 2 * (this->length + this->breadth);}
        bool isSquare() {return this->length == this->breadth;}
        ~Rectangle() {cout << "Destroyed";}
};

class Cuboid : public Rectangle {
    private:
        int height;

    public:
        Cuboid(int height) {this->height = height;}
        int getHeight() {return height;}
        void setHeight(int height) {this->height = height;}
        int volume() {return area() * height;}
};

int main() {
    Cuboid c(5);
    c.setLength(10);
    c.setBreadth(7);
    cout << "Volume is " << c.volume() << endl;
}

Rectangle::Rectangle(int length = 1, int breadth = 1) {
    this->length = length;
    this->breadth = breadth;
}
Rectangle::Rectangle(Rectangle &rectangle) {
    this->length = rectangle.length;
    this->breadth = rectangle.breadth;
}