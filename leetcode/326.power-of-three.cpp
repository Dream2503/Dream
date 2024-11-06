/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double logResult = log10(n) / log10(3);
        return floor(logResult) == logResult;
    }
};
// @lc code=end

