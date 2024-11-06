/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
    queue<int> stack;
public:
    MyStack() {}
    void push(int x) {stack.push(x);}
    int pop() {
        for (int i = 1; i < stack.size(); i++) {
            stack.push(stack.front());
            stack.pop();
        }
        int res = stack.front();
        stack.pop();
        return res;
    }
    int top() {return stack.back();}
    bool empty() {return stack.empty();}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

