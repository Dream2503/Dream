#include <iostream>
using namespace std;

template <class type>
class SortedLinkedList {
    struct Node {
        type data = 0;
        Node *next = nullptr;
    }; 
    Node *head = nullptr;
    string mode = "asc";
    bool operators(SortedLinkedList<type>, string);

    public:
        SortedLinkedList() {}
        SortedLinkedList(initializer_list<type> list) {for (const type element: list) this->insert(element);}
        SortedLinkedList(SortedLinkedList<type>&);
        SortedLinkedList(type *list, int size) {for (int i = 0; i < size; i++) this->insert(list[i]);}
        double average() {return this->sum() / (double)this->length();}
        void clear();
        bool contains(type);
        SortedLinkedList<type> copy() {return *this;}
        int count(type);
        void display() {operator<<(cout, *this);}
        void extend(SortedLinkedList<type> list) {*this += list;}
        int index(type);
        void insert(type);
        int length();
        type max();
        type min();
        SortedLinkedList<type> operator+(SortedLinkedList<type>);
        void operator+=(SortedLinkedList<type>);
        SortedLinkedList<type> operator*(int);
        void operator*=(int);
        bool operator>(SortedLinkedList<type> list) {return this->operators(list, ">");}
        bool operator>=(SortedLinkedList<type> list) {return this->operators(list, ">=");}
        bool operator<(SortedLinkedList<type> list) {return this->operators(list, "<");}
        bool operator<=(SortedLinkedList<type> list) {return this->operators(list, "<=");}
        bool operator==(SortedLinkedList<type> list) {return this->operators(list, "==");}
        bool operator!=(SortedLinkedList<type> list) {return not (*this == list);}
        template <class T>
        friend ostream &operator<<(ostream&, SortedLinkedList<T>);
        type operator[](int index);
        type pop(int);
        void remove(type);
        void reverse();
        type sum();
};
template <class type>
SortedLinkedList<type>::SortedLinkedList(SortedLinkedList<type>& list) {
    this->mode = list.mode;
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
template <class type>
bool SortedLinkedList<type>::operators(SortedLinkedList<type> list, string opr) {
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
void SortedLinkedList<type>::clear() {
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
bool SortedLinkedList<type>::contains(type value) {
    Node *current = this->head;

    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
template <class type>
int SortedLinkedList<type>::count(type value) {
    Node *current = this->head;
    int cnt = 0;
    
    while (current) {
        if (current->data == value) {
            while (current->data == value) {
                cnt++;
                current = current->next;
            }
            return cnt;
        }
        current = current->next;
    }
    return cnt;
}
template <class type>
int SortedLinkedList<type>::index(type value) {
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
void SortedLinkedList<type>::insert(type value) {
    if (not this->head) {
        this->head = new Node;
        this->head->data = value;
        return;
    }
    Node *current = this->head, *prev = nullptr;

    while (current) {
        if ((this->mode == "asc" and current->data >= value)or (this->mode == "dsc" and current->data <= value)) {
            if (not prev) {
                prev = new Node;
                prev->data = value;
                prev->next = current;
                this->head = prev;
            } else {
                prev->next = new Node;
                prev = prev->next;
                prev->data = value;
                prev->next = current;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    prev->next = new Node;
    prev->next->data = value;
}
template <class type>
int SortedLinkedList<type>::length() {
    Node *current = this->head;
    int len = 0;

    while (current) {
        len++;
        current = current->next;
    }
    return len;
}
template <class type>
type SortedLinkedList<type>::max() {
    if (not this->head) return 0;
    if (this->mode == "dsc") return this->head->data;
    Node *current = this->head;
    while (current->next) current = current->next;
    return current->data;
}
template <class type>
type SortedLinkedList<type>::min() {
    if (not this->head) return 0;
    if (this->mode == "asc") return this->head->data;
    Node *current = this->head;
    while (current->next) current = current->next;
    return current->data;
}
template <class type>
SortedLinkedList<type> SortedLinkedList<type>::operator+(SortedLinkedList<type> list) {
    if (this->mode != list->mode) list.reverse();
    if (not this->head) return list;
    if (not list.head) return *this;
    SortedLinkedList<type> result;
    Node *current1 = this->head, *current2 = list.head, *current;
    result.head = new Node;

    if ((this->mode == "asc" and current1->data < current2->data) or (this->mode == "dsc" and current1->data > current2->data)) {
        result.head->data = current1->data;
        current1 = current1->next;
    } else {
        result.head->data = current2->data;
        current2 = current2->next;
    }
    current = result.head;

    while (current1 and current2) {
        current->next = new Node;
        current = current->next;

        if ((this->mode == "asc" and current1->data < current2->data) or (this->mode == "dsc" and current1->data > current2->data)) {
            current->data = current1->data;
            current1 = current1->next;
        } else if ((this->mode == "asc" and current1->data > current2->data) or (this->mode == "dsc" and current1->data < current2->data)) {
            current->data = current2->data;
            current2 = current2->next;
        } else {
            current->data = current1->data;
            current1 = current1->next;
            current->next = new Node;
            current = current->next;
            current->data = current2->data;
            current2 = current2->next;
        }
    }
    while (current1) {
        current->next = new Node;
        current = current->next;
        current->data = current1->data;
        current1 = current1->next;
    }
    while (current2) {
        current->next = new Node;
        current = current->next;
        current->data = current2->data;
        current2 = current2->next;
    }
}
template <class type>
void SortedLinkedList<type>::operator+=(SortedLinkedList<type> list) {
    SortedLinkedList<type> result = this->operator+(list);
    this->clear();
    *this = result;
}
template <class type>
SortedLinkedList<type> SortedLinkedList<type>::operator*(int num) {
    SortedLinkedList<type> result;

    if (num < 0) {
        cout << "Invalid number";
        exit(0);
    }
    if (not this->head or num == 0) return result;
    if (num == 1) return *this;
    Node *prev = this->head, current = prev->next;

    for (int i = 1; i < num; i++) {
        prev->next = new Node;
        prev->next->data = prev->data;
        prev = prev->next;
        prev->next = current;
    }

    while (current) {
        for (int i = 1; i < num; i++) {
            prev->next = new Node;
            prev = prev->next;
            prev->data = current->data;
            prev->next = current;
        }
        current = current->next;
    }
    return result;
}
template <class type>
void SortedLinkedList<type>::operator*=(int num) {
    SortedLinkedList<type> result = this->operator*(num);
    this->clear();
    *this = result;
}
template <class T>
ostream &operator<<(ostream &out, SortedLinkedList<T> list) {
    if (not list.head) out << "No elements to display" << endl;
    else {
        typename SortedLinkedList<T>::Node *current = list.head;
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
type SortedLinkedList<type>::operator[](int index) {
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
type SortedLinkedList<type>::pop(int index) {
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
void SortedLinkedList<type>::remove(type value) {
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
void SortedLinkedList<type>::reverse() {
    if (this->mode == "asc") this->mode = "dsc";
    else this->mode = "dsc";
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
type SortedLinkedList<type>::sum() {
    if (not this->head) return 0;
    type sum = this->head->data;
    Node *current = this->head->next;

    while (current) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}