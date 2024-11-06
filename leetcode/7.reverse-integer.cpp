/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0) neg = true;
        string res = to_string(x);
        if (neg) res.erase(res.begin());
        std::reverse(res.begin(), res.end());
        long num = stol(res);
        if (neg) num *= -1;
        if (num < INT_MIN or num > INT_MAX) return 0;
        return (int)num;
    }
};
// @lc code=end

