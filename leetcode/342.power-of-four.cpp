/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        double logResult = log(n) / log(4);
        return floor(logResult) == logResult;
    }
};
// @lc code=end

