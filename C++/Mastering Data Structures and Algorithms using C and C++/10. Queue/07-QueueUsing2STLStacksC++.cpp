#include <iostream>
#include <stack>

using namespace std;
 
class Queue{
private:
    stack<int> e_stk;
    stack<int> d_stk;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};
 
void Queue::enqueue(int x) {
    e_stk.push(x);
}
 
int Queue::dequeue() {
    int x = -1;
    if (d_stk.empty()){
        if (e_stk.empty()){
            cout << "Queue Underflow" << endl;
            return x;
        } else {
            while (!e_stk.empty()){
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    x = d_stk.top();
    d_stk.pop();
    return x;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    cout << "Enqueue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
    cout << endl;
 
    cout << "Dequeue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << q.dequeue() << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
 
    return 0;
}