/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <iostream>
using namespace std;

class Stack {
    class Node {
        public:
            char data;
            Node *next = nullptr;
    };
    Node *top = nullptr;

    public:
        Stack() {}
        bool isEmpty() {return this->top == nullptr;}
        char pop() {
            Node *temp = this->top;
            char value = temp->data;
            this->top = this->top->next;
            delete temp;
            return value;
        }
        void push(char value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = this->top;
            this->top = temp;
        }
};
class Solution {
public:
    bool isValid(string s) {
        Stack stk;
        char chk;
        
        for (char ch: s) {
            if (ch == '(' or ch == '[' or ch == '{') stk.push(ch);
            else {
                if (stk.isEmpty()) return false;
                chk = stk.pop();
                if (chk == ch - 1 or chk == ch - 2) continue;
                return false;
            }
        }
        if (stk.isEmpty()) return true;
        return false;
    }
};
// @lc code=end

([)]