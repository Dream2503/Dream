#include <iostream>
using namespace std;

template <class type>
class LinkedList {
    struct Node {
        type data = 0;
        Node *next = nullptr;
    };
    Node *head = nullptr;
    bool operators(LinkedList<type>, string);

    public:
        LinkedList() {}
        LinkedList(initializer_list<type>);
        LinkedList(LinkedList<type>&);
        LinkedList(type*, int);
        void append(type);
        double average() {return this->sum() / (double)this->length;}
        void clear();
        bool contains(type);
        LinkedList<type> copy() {return *this;}
        int count(type);
        void display() {operator<<(cout, *this);}
        void extend(LinkedList<type>);
        int index(type);
        void insert(int, type);
        bool isSorted();
        int length();
        void leftRotate();
        void leftShift();
        type max();
        type min();
        LinkedList<type> operator+(LinkedList<type>);
        void operator+=(LinkedList<type> list) {this->extend(list);}
        LinkedList<type> operator*(int);
        void operator*=(int num) {*this = *this * num;}
        bool operator>(LinkedList<type> list) {return this->operators(list, ">");}
        bool operator>=(LinkedList<type> list) {return this->operators(list, ">=");}
        bool operator<(LinkedList<type> list) {return this->operators(list, "<");}
        bool operator<=(LinkedList<type> list) {return this->operators(list, "<=");}
        bool operator==(LinkedList<type> list) {return this->operators(list, "==");}
        bool operator!=(LinkedList<type> list) {return not (*this == list);}
        template <class T>
        friend ostream &operator<<(ostream&, LinkedList<T>);
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
LinkedList<type>::LinkedList(initializer_list<type> list) {
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
            current = current->next;
            current->data = element;
        }
    }
}
template <class type>
LinkedList<type>::LinkedList(LinkedList<type> &list) {
    if (list.head) {
        this->head = new Node;
        this->head->data = list.head->data;
        Node *current1 = this->head, *current2 = list.head->next;

        while (current2) {
            current1->next = new Node;
            current1 = current1->next;
            current1->data = current2->data;
            current2 = current2->next;
        }
    }
}
template <class type>
LinkedList<type>::LinkedList(type *array, int size) {
    if (size > 0) {
        this->head = new Node;
        this->head->data = array[0];
        Node *current = this->head;

        for (int i = 1; i < size; i++) {
            current->next = new Node;
            current = current->next;
            current->data = array[i];
        }
    }
}
template <class type>
bool LinkedList<type>::operators(LinkedList<type> list, string opr) {
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
void LinkedList<type>::append(type value) {
    if (not this->head) {
        this->head = new Node;
        this->head->data = value;
        return;
    }
    Node *current = this->head;
    while (current->next) current = current->next;
    current->next = new Node;
    current->next->data = value;
}
template <class type>
void LinkedList<type>::clear() {
    if (not this->head) return;
    Node *prev = this->head, *current = prev->next;
    
    while (current) {
        delete prev;
        prev = current;
        current = current->next;
    }
    delete prev;
    this->head = nullptr;
}
template <class type>
bool LinkedList<type>::contains(type value) {
    Node *current = this->head;

    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
template <class type>
int LinkedList<type>::count(type value) {
    Node *current = this->head;
    int cnt = 0;
    
    while (current) {
        if (current->data == value) cnt++;
        current = current->next;
    }
    return cnt;
}
template <class type>
void LinkedList<type>::extend(LinkedList<type> list) {
    LinkedList<type> result(list);
    if (not this->head) this->head = result.head;
    else {
        Node *current = this->head;
        while (current->next) current = current->next;
        current->next = result.head;
    }
}
template <class type>
int LinkedList<type>::index(type value) {
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
void LinkedList<type>::insert(int index, type value) {
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
        current = current->next;
        current->data = value;
        current->next = temp;
    }
}
template <class type>
bool LinkedList<type>::isSorted() {
    if (not this->head) return true;
    Node *current = this->head;

    while (current->next) {
        if (current->data > current->next->data) return false;
        current = current->next;
    }
    return true;
}
template <class type>
int LinkedList<type>::length() {
    Node *current = this->head;
    int len = 0;

    while (current) {
        len++;
        current = current->next;
    }
    return len;
}
template <class type>
void LinkedList<type>::leftRotate() {
    if (not (this->head and this->head->next)) return;
    Node *element = this->head, *current = this->head->next;
    this->head = this->head->next;
    while (current->next) current = current->next;
    current->next = element;
    element->next = nullptr;
}
template <class type>
void LinkedList<type>::leftShift() {
    if (not this->head) return;
    else if (not this->head->next) this->head->data = 0;
    else {
        this->pop(0);
        Node *current = this->head;
        while (current->next) current = current->next;
        current->next = new Node;
        current->next->data = 0;
    }
}
template <class type>
type LinkedList<type>::max() {
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
type LinkedList<type>::min() {
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
LinkedList<type> LinkedList<type>::operator+(LinkedList<type> list) {
    LinkedList<type> list1(*this);
    list1.extend(list);
    return list1;
}
template <class type>
LinkedList<type> LinkedList<type>::operator*(int num) {
    LinkedList<type> list, result(*this);

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
        }
        return result;
    } 
}
template <class T>
ostream &operator<<(ostream &out, LinkedList<T> list) {
    if (not list.head) out << "No elements to display" << endl;
    else {
        typename LinkedList<T>::Node *current = list.head;
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
type &LinkedList<type>::operator[](int index) {
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
type LinkedList<type>::pop(int index) {
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
void LinkedList<type>::rightRotate() {
    if (not (this->head and this->head->next)) return;
    Node *prev = this->head, *current = prev->next;

    while (current->next) {
        prev = current;
        current = current->next;
    }
    prev->next = nullptr;
    current->next = this->head;
    this->head = current;
}
template <class type>
void LinkedList<type>::rightShift() {
    if (not this->head) return;
    else if (not this->head->next) this->head->data = 0;
    else {
        this->insert(0, 0);
        Node *prev = this->head, *current = prev->next;

        while (current->next) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        delete current;
    }
}
template <class type>
void LinkedList<type>::remove(type value) {
    if (not this->head) return;
    if (this->head->data == value) {
        Node *temp = this->head;
        this->head = temp->next;
        delete temp;
        return;
    }
    Node *prev = this->head, *current = prev->next;

    while (current) {
        if (current->data == value){
            prev->next = current->next;
            delete current;
        }
        prev = current;
        current = current->next;
    }
}
template <class type>
void LinkedList<type>::reverse() {
    if (not (this->head and this->head->next)) return;
    Node *end = nullptr, *prev = this->head, *current = prev->next;

    while (current) {
        prev->next = end;
        end = prev;
        prev = current;
        current = current->next;
    }
    prev->next = end;
    this->head = prev;
}
template <class type>
type LinkedList<type>::sum() {
    if (not this->head) return 0;
    type sum = this->head->data;
    Node *current = this->head->next;

    while (current) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}