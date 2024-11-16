#include <iostream>
#define CONST_SIZE 8
using namespace std;

template <class type>
class Set {
    type *list = new type[CONST_SIZE];
    int len = 0, size = CONST_SIZE;
    bool operators(Set<type>, string);
    void reSize();
    
    public:
        Set() {}
        Set(initializer_list<type> list) {for (const type element: list) this->append(element);}
        Set(Set<type> &set) {for (type element: set) this->append(element);}
        Set(type *list, int size) {for (int i = 0; i < size; i++) this->append(list[i]);}
        void append(type);
        double average() {return this->sum() / (double)this->len;}
        type *begin() {return this->list;}
        void clear();
        bool contains(type);
        Set<type> copy() {return *this;}
        void display() {operator<<(cout, *this);}
        Set<type> difference(Set<type>);
        type *end() {return this->list + this->len;}
        int index(type);
        void insert(int, type);
        Set<type> intersection(Set<type>);
        bool isSorted();
        int length() {return this->len;}
        void leftRotate();
        void leftShift();
        type max();
        type min();
        Set<type> operator+(Set<type> set) {return this->Union(set);}
        void operator+=(Set<type> set);
        bool operator>(Set<type> set) {return this->operators(set, ">");}
        bool operator>=(Set<type> set) {return this->operators(set, ">=");}
        bool operator<(Set<type> set) {return this->operators(set, "<");}
        bool operator<=(Set<type> set) {return this->operators(set, "<=");}
        bool operator==(Set<type> set) {return this->operators(set, "==");}
        bool operator!=(Set<type> set) {return not (*this == set);}
        template <class T>
        friend ostream &operator<<(ostream&, Set<T>);
        type &operator[](int);
        type pop(int);
        void rightRotate();
        void rightShift();
        void remove(type);
        void reverse();
        void sort();
        type sum();
        Set<type> Union(Set<type>);
};


template <class type>
bool Set<type>::operators(Set<type> array, string opr) {
    int small = this->len;
    if (this->len > array.len) small = array.len;

    for (int i = 0; i < small; i++) {
        if ((opr == ">") and (this->list[i] <= array[i])) return false;
        else if ((opr == ">=") and (this->list[i] < array[i])) return false;
        else if ((opr == "<") and (this->list[i] >= array[i])) return false;
        else if ((opr == "<=") and (this->list[i] > array[i])) return false;
        else if ((opr == "==") and (this->list[i] != array[i] and this->len != array.len)) return false;
    }
    return true;
}
template <class type>
void Set<type>::reSize() {
    this->size *= 2;
    type *list = new type[this->size];
    for (int i = 0; i < this->len; i++) list[i] = this->list[i];
    delete []this->list;
    this->list = list;
}

template <class type>
void Set<type>::append(type value) {
    if (this->len == this->size) this->reSize();
    if (not this->contains(value)) this->list[this->len++] = value;
}
template <class type>
void Set<type>::clear() {
    delete []this->list;
    this->len = 0;
    this->list = new type[CONST_SIZE];
    this->size = CONST_SIZE;
}
template <class type>
bool Set<type>::contains(type value) {
    if (this->index(value) == -1) return false;
    return true;
}
template <class type>
Set<type> Set<type>::difference(Set<type> set) {
    Set<type> result;
    bool found = false;

    for (int i = 0; i < this->len; i++) {
        for (int j = 0; j < set.len; j++)
            if (this->list[i] == set[j]) {
                found = true;
                break;
            }
        if (not found) result.append((*this)[i]);
        else found = false;
    }
    return result;
}
template <class type>
int Set<type>::index(type value) {
    for (int i = 0; i < this->len; i++) if (this->list[i] == value) return i;
    return -1;
}
template <class type>
void Set<type>::insert(int index, type value) {
    if (this->len == this->size) this->reSize();
    if (index > this->len) {
        cout << "Index out of range";
        exit(0);
    }
    if (this->contains(value)) return;
    for (int i = this->len++; i > index; i--) this->list[i] = this->list[i-1];
    this->list[index] = value;
}
template <class type>
Set<type> Set<type>::intersection(Set<type> set) {
    Set<type> result;

    for (int i = 0; i < this->len; i++)
        for (int j = 0; j < set.len; j++)
            if ((*this)[i] == set[j])
                result.append(set[j]);
    
    return result;
}
template <class type>
bool Set<type>::isSorted() {
    for (int i = 1; i < this->len; i++) if (this->list[i] < this->list[i-1]) return false;
    return true;
}
template <class type>
void Set<type>::leftRotate() {
    type temp = this->pop(0);
    this->len++;
    this->list[this->len-1] = temp;
}
template <class type>
void Set<type>::leftShift() {
    this->remove(0);
    this->len++;
    this->list[this->len-1] = 0;
}
template <class type>
type Set<type>::max() {
    type max = this->list[0];
    for (int i = 1; i < this->len; i++) if (this->list[i] > max) max = this->list[i];
    return max;
}
template <class type>
type Set<type>::min() {
    type min = this->list[0];
    for (int i = 1; i < this->len; i++) if (this->list[i] <  min) min = this->list[i];
    return min;
}
template <class type>
void Set<type>::operator+=(Set<type> set) {
    Set<type> res = this->Union(set);
    delete []this->list;
    *this = res;
}
template <class T>
ostream &operator<<(ostream &out, Set<T> set) {
    if (not set.len) out << "No elements to display" << endl;
    else {
        out << '[';

        for (int i = 0; i < set.len; i++) {
            out << set[i];
            if (i != set.len - 1) out << ", ";
        }
        out << ']' << endl;
    }
    return out;
}
template <class type>
type &Set<type>::operator[](int index) {
    if (index >= this->len or index < 0) {
        cout << "Index out of range";
        exit(0);
    }
    return this->list[index];
}
template <class type>
type Set<type>::pop(int index) {
    if (index >= this->len) {
        cout << "Index out of range";
        exit(0);
    }
    type temp = this->list[index];
    for (int i = index; i < this->len - 1; i++) this->list[i] = this->list[i+1];
    this->len--;
    return temp;
}
template <class type>
void Set<type>::rightRotate() {
    type temp = this->list[this->len-1];
    this->insert(0, temp);
    this->len--;
}
template <class type>
void Set<type>::rightShift() {
    this->insert(0, 0);
    this->len--;
}
template <class type>
void Set<type>::remove(type value) {
    int index = this->index(value);
    this->pop(index);
}
template <class type>
void Set<type>::reverse() {
    for (int i = 0, j = this->len - 1; i < j; i++, j--){
        type temp = this->list[i];
        this->list[i] = this->list[j];
        this->list[j] = temp;
    }
}
template <class type>
type Set<type>::sum() {
    type sum = 0;
    for (int i = 0; i < this->len; i++) sum += this->list[i];
    return sum;
}
template <class type>
Set<type> Set<type>::Union(Set<type> set) {
    Set<type> res(*this);
    for (int i = 0; i < set.len; i++) this->append(set[i]);
    return res;
}