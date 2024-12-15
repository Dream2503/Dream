#include <iostream>
using namespace std;

class Shape {
    public:
        virtual float area() = 0, perimeter() = 0;
};

class Rectangle: public Shape {
    private:
        float length, breadth;

    public:
    Rectangle(int length = 1, int breadth = 1) {
        this->length = length;
        this->breadth = breadth;
    }
    float area() {return this->length * this->breadth;}
    float perimeter() {return 2 * (this->length + this->breadth);}
};
class Circle: public Shape {
    private:
        float radius;
        const float pi = 3.14159;

    public:
        Circle(float radius) {this->radius = radius;}
        float area() {return this->pi * this->radius * this->radius;}
        float perimeter() {return 2 * this->pi * this->radius;}
};

int main() {
    Shape *s = new Rectangle(10, 5);
    cout << "Area of Rectangle " << s->area() << endl;
    cout << "Perimeter of Rectangle " << s->perimeter() << endl;

    s = new Circle(10);
    cout << "Area of Circle " << s->area() << endl;
    cout << "Perimeter of Circle " << s->perimeter() << endl;
    return 0;
}