#include <iostream>
#include<cstring>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
    Node *top;

public:
    Stack();

    ~Stack();

    void push(int x);

    int pop();

    int peek(int index);

    int isEmpty();

    int isFull();

    int stackTop();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node *p = top;

    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(int x) {
    Node *t = new Node;

    if (!t) {
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    Node *p;
    int x = -1;

    if (!top) {
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::isFull() {
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}

int Stack::stackTop() {
    if (top) {
        return top->data;
    }
    return -1;
}

int Stack::peek(int index) {
    if (isEmpty()) {
        return -1;
    }
    Node *p = top;

    for (int i = 0; p != nullptr && i < index - 1; i++) {
        p = p->next;
    }

    if (p != nullptr) {
        return p->data;
    }
    return -1;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

int operation(char op, int x, int y) {
    if (op == '+') {
        return x + y;
    }
    if (op == '-') {
        return x - y;
    }
    if (op == '*') {
        return x * y;
    }
    if (op == '/') {
        return x / y;
    }
}

int postfixEvaluate(char *postfix) {
    stack<int> stk;
    int x, y, result;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            // int typecast would not work because of char so subtract '0'
            stk.push(postfix[i] - '0');
        } else {
            y = stk.top();
            stk.pop();
            x = stk.top();
            stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.top();
    stk.pop();
    return result;
}

int Evaluate(char *postfix) {
    Stack stk;
    int x, y, result;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            // int typecast would not work because of char so subtract '0'
            stk.push(postfix[i] - '0');
        } else {
            y = stk.pop();
            x = stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}

int main() {
    char postfix[] = "35*62/+4-";
    cout << Evaluate(postfix) << endl;
    cout << postfixEvaluate(postfix) << endl;

    return 0;
}
