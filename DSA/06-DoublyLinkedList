#include <iostream>
using namespace std;

template <class type>
class DoublyLinkedList {
    struct Node {
        type data = 0;
        Node *prev = nullptr, *next = nullptr;
    };
    Node *head = nullptr;
    bool operators(DoublyLinkedList<type>, string);

    public:
        DoublyLinkedList() {}
        DoublyLinkedList(initializer_list<type>);
        DoublyLinkedList(DoublyLinkedList<type>&);
        DoublyLinkedList(type*, int);
        void append(type);
        double average() {return this->sum() / (double)this->length;}
        void clear();
        bool contains(type);
        DoublyLinkedList<type> copy() {return *this;}
        int count(type);
        void display() {operator<<(cout, *this);}
        void extend(DoublyLinkedList<type>);
        int index(type);
        void insert(int, type);
        bool isSorted();
        int length();
        void leftRotate();
        void leftShift();
        type max();
        type min();
        DoublyLinkedList<type> operator+(DoublyLinkedList<type>);
        void operator+=(DoublyLinkedList<type> list) {this->extend(list);}
        DoublyLinkedList<type> operator*(int);
        void operator*=(int num) {*this = *this * num;}
        bool operator>(DoublyLinkedList<type> list) {return this->operators(list, ">");}
        bool operator>=(DoublyLinkedList<type> list) {return this->operators(list, ">=");}
        bool operator<(DoublyLinkedList<type> list) {return this->operators(list, "<");}
        bool operator<=(DoublyLinkedList<type> list) {return this->operators(list, "<=");}
        bool operator==(DoublyLinkedList<type> list) {return this->operators(list, "==");}
        bool operator!=(DoublyLinkedList<type> list) {return not (*this == list);}
        template <class T>
        friend ostream &operator<<(ostream&, DoublyLinkedList<T>);
        type &operator[](int);
        type pop(int);
        void rightRotate();
        void rightShift();
        void remove(type);
        void reverse();
        void sort();
        type sum();

};
template <class type>
DoublyLinkedList<type>::DoublyLinkedList(initializer_list<type> list) {
    bool onHead = true;
    Node *current;
    
    for (const type element: list) {
        if (onHead) {
            this->head = new Node;
            this->head->data = element;
            current = this->head;
            onHead = false;
        } else {
            current->next = new Node;
            current->next->prev = current;
            current = current->next;
            current->data = element;
        }
    }
}
template <class type>
DoublyLinkedList<type>::DoublyLinkedList(DoublyLinkedList<type> &list) {
    if (list.head) {
        this->head = new Node;
        this->head->data = list.head->data;
        Node *current1 = this->head, *current2 = list.head->next;

        while (current2) {
            current1->next = new Node;
            current1->next->prev = current1;
            current1 = current1->next;
            current1->data = current2->data;
            current2 = current2->next;
        }
    }
}
template <class type>
DoublyLinkedList<type>::DoublyLinkedList(type *array, int size) {
    if (size > 0) {
        this->head = new Node;
        this->head->data = array[0];
        Node *current = this->head;

        for (int i = 1; i < size; i++) {
            current->next = new Node;
            current->next->prev = current;
            current = current->next;
            current->data = array[i];
        }
    }
}
template <class type>
bool DoublyLinkedList<type>::operators(DoublyLinkedList<type> list, string opr) {
    Node *current1 = this->head, *current2 = list.head;

    while (current1 and current2) {
        if ((opr == ">") and (current1->data <= current2->data)) return false;
        else if ((opr == ">=") and (current1->data < current2->data)) return false;
        else if ((opr == "<") and (current1->data >= current2->data)) return false;
        else if ((opr == "<=") and (current1->data > current2->data)) return false;
        else if ((opr == "==") and (current1->data != current2->data)) return false;
        current1 = current1->next;
        current2 = current2->next;
    }
    if ((current1 or current2) and (opr == "==")) return false;
    return true;
}

template <class type>
void DoublyLinkedList<type>::append(type value) {
    if (not this->head) {
        this->head = new Node;
        this->head->data = value;
        return;
    }
    Node *current = this->head;
    while (current->next) current = current->next;
    current->next = new Node;
    current->next->prev = current;
    current->next->data = value;
}
template <class type>
void DoublyLinkedList<type>::clear() {
    if (not this->head) return;
    Node *current = this->head;
    
    while (current->next) {
        delete current->prev;
        current = current->next;
    }
    delete current;
    this->head = nullptr;
}
template <class type>
bool DoublyLinkedList<type>::contains(type value) {
    Node *current = this->head;

    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
template <class type>
int DoublyLinkedList<type>::count(type value) {
    Node *current = this->head;
    int cnt = 0;
    
    while (current) {
        if (current->data == value) cnt++;
        current = current->next;
    }
    return cnt;
}
template <class type>
void DoublyLinkedList<type>::extend(DoublyLinkedList<type> list) {
    DoublyLinkedList<type> result(list);
    if (not this->head) this->head = result.head;
    else {
        Node *current = this->head;
        while (current->next) current = current->next;
        current->next = result.head;
        result.head->prev = current;
    }
}
template <class type>
int DoublyLinkedList<type>::index(type value) {
    Node *current = this->head;
    int cnt = 0;

    while (current) {
        if (current->data == value) return cnt;
        current = current->next;
        cnt++;
    }
    return -1;
}
template <class type>
void DoublyLinkedList<type>::insert(int index, type value) {
    if (index < 0 or ((not this->head) and index > 0)) {
        cout << "Index out of range";
        exit(0);
    } else if (not this->head) {
        this->head = new Node;
        this->head->data = value;
    } else if (index == 0) {
        Node *current = this->head;
        this->head = new Node;
        this->head->data = value;
        this->head->next = current;
    } else {
        Node *temp, *current = this->head;

        for (int i = 0; i < index - 1; i++) {
            if (current->next) current = current->next;
            else {
                cout << "Index out of range";
                exit(0);
            }
        }
        temp = current->next;
        current->next = new Node;
        current->next->prev = current;
        current = current->next;
        current->data = value;
        current->next = temp;
        temp->prev = current;
    }
}
template <class type>
bool DoublyLinkedList<type>::isSorted() {
    if (not this->head) return true;
    Node *current = this->head;

    while (current->next) {
        if (current->data > current->next->data) return false;
        current = current->next;
    }
    return true;
}
template <class type>
int DoublyLinkedList<type>::length() {
    Node *current = this->head;
    int len = 0;

    while (current) {
        len++;
        current = current->next;
    }
    return len;
}
template <class type>
void DoublyLinkedList<type>::leftRotate() {
    if (not (this->head and this->head->next)) return;
    Node *element = this->head, *current = this->head->next;
    this->head = this->head->next;
    this->head->prev = nullptr;
    while (current->next) current = current->next;
    current->next = element;
    element->prev = current;
    element->next = nullptr;
}
template <class type>
void DoublyLinkedList<type>::leftShift() {
    if (not this->head) return;
    else if (not this->head->next) this->head->data = 0;
    else {
        this->pop(0);
        Node *current = this->head;
        while (current->next) current = current->next;
        current->next = new Node;
        current->next->prev = current;
        current->next->data = 0;
    }
}
template <class type>
type DoublyLinkedList<type>::max() {
    if (not this->head) return 0;
    Node *current = this->head->next;
    type max = this->head->data;

    while (current) {
        if (current->data > max) max = current->data;
        current = current->next;
    }
    return max;
}
template <class type>
type DoublyLinkedList<type>::min() {
    if (not this->head) return 0;
    Node *current = this->head->next;
    type min = this->head->data;

    while (current) {
        if (current->data < min) min = current->data;
        current = current->next;
    }
    return min;
}
template <class type>
DoublyLinkedList<type> DoublyLinkedList<type>::operator+(DoublyLinkedList<type> list) {
    DoublyLinkedList<type> list1(*this);
    list1.extend(list);
    return list1;
}
template <class type>
DoublyLinkedList<type> DoublyLinkedList<type>::operator*(int num) {
    DoublyLinkedList<type> list, result(*this);

    if (num < 0) {
        cout << "Invalid number";
        exit(0);
    } else if (not this->head or num == 0) return list;
    else if (num == 1) return this->copy();
    else {
        Node *current = result.head;

        for (int i = 1; i < num; i++ ) {
            list = this->copy();
            while (current->next) current = current->next;
            current->next = list.head;
            list.head->prev = current;
        }
        return result;
    } 
}
template <class T>
ostream &operator<<(ostream &out, DoublyLinkedList<T> list) {
    if (not list.head) out << "No elements to display" << endl;
    else {
        typename DoublyLinkedList<T>::Node *current = list.head;
        out << '[';

        while (current->next) {
            out << current->data << ", ";
            current = current->next;
        }
        out << current->data << ']' << endl;
    }
    return out;
}
template <class type>
type &DoublyLinkedList<type>::operator[](int index) {
    if (index < 0 or ((not this->head) and index > 0)) {
        cout << "Index out of range";
        exit(0);
    }
    Node *current = this->head;

    for (int i = 0 ; i < index and current; i++) {
        current = current->next;
    }
    if (current) return current->data;
    cout << "Index out of range";
    exit(0);
}
template <class type>
type DoublyLinkedList<type>::pop(int index) {
    if (not this->head or index < 0) {
        cout << "Index out of range";
        exit(0);
    }
    Node *temp;
    type value;

    if (index == 0) {
        temp = this->head;
        value = temp->data;
        this->head = temp->next;
        delete temp;
    } else {
        Node *current = this->head;

        for (int i = 0; i < index; i++) {
            if (current->next) {
                temp = current;
                current = current->next;
            } else {
                cout << "Index out of range";
                exit(0);
            }
        }
        temp->next = current->next;
        delete current;
    }
    return value;
}
template <class type>
void DoublyLinkedList<type>::rightRotate() {
    if (not (this->head and this->head->next)) return;
    Node *current = this->head->next;
    while (current->next) current = current->next;
    current->prev->next = nullptr;
    current->next = this->head;
    this->head->prev = current;
    this->head = current;
}
template <class type>
void DoublyLinkedList<type>::rightShift() {
    if (not this->head) return;
    else if (not this->head->next) this->head->data = 0;
    else {
        this->insert(0, 0);
        Node *current = this->head->next;
        while (current->next) current = current->next;
        current->next->next = nullptr;
        delete current;
    }
}
template <class type>
void DoublyLinkedList<type>::remove(type value) {
    if (not this->head) return;
    if (this->head->data == value) {
        Node *temp = this->head;
        this->head = temp->next;
        delete temp;
        return;
    }
    Node *current = this->head->next;

    while (current) {
        if (current->data == value){
            current->prev->next = current->next;
            delete current;
        }
        current = current->next;
    }
}
template <class type>
void DoublyLinkedList<type>::reverse() {
    if (not (this->head and this->head->next)) return;
    Node *current = this->head, *temp;
    
    while (current->next) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }
    current->next = temp->prev;
    this->head = current;
    this->head->prev = nullptr;
}
template <class type>
type DoublyLinkedList<type>::sum() {
    if (not this->head) return 0;
    type sum = this->head->data;
    Node *current = this->head->next;

    while (current) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}