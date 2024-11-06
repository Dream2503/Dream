/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int temp, sum;

        for (string str: operations) {
            if (str == "+") {
                temp = stk.top();
                stk.pop();
                sum = stk.top() + temp;
                stk.push(temp); stk.push(sum);
            } else if (str == "D") stk.push(2*stk.top());
            else if (str == "C") stk.pop();
            else stk.push(stoi(str));
        }
        sum = 0;

        while (not stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
// @lc code=end

