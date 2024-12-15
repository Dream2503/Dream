#include <iostream>
using namespace std;

class StackOverFlow: exception{};
class StackUnderFlow: exception{};

class Stack {
    private:
        int *stack, top = -1, size;
    public:
        Stack(int size) {
        this->size = size;
        this->stack = new int[size];
    }
    void push(int x) {
        if(this->top == this->size-1)
            throw StackOverFlow();

        this->top++;
        this->stack[this->top] = x;
    }
    int pop() {
        if(this->top == -1)
            throw StackUnderFlow();
        return this->stack[this->top--];
    }
};

int main() {
    Stack s(5);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(10);
    s.push(9);
    s.push(8);
    return 0;
}