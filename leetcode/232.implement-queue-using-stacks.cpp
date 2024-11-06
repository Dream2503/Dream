/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    stack<int> main, alt;
public:
    MyQueue() {}
    void push(int x) {main.push(x);}
    int pop() {
        int res = peek();
        alt.pop();
        return res;
    }
    int peek() {
        if (alt.empty()) 
            while (not main.empty()) {
                alt.push(main.top());
                main.pop();
            }
        return alt.top();
    }
    bool empty() {return main.empty() and alt.empty();}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

