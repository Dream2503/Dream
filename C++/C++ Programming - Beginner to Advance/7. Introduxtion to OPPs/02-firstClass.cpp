class Rectangle {
    public:
        int length;
        int breadth;

        int area() {
            return length*breadth;
        }
        int perimeter() {
            return 2*(length+breadth);
        }
};

int main() {
    return 0;
}