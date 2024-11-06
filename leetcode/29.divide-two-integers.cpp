/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        long res = dividend / (long)divisor;
        if (res > INT_MAX) return INT_MAX;
        else if (res < INT_MIN) return INT_MIN;
        return res;
    }
};
// @lc code=end

