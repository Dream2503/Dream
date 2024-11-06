/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        unsigned int multiplier = 1, res = 0;

        for (unsigned int ch: columnTitle) {
            res += (ch - 64) * multiplier;
            multiplier *= 26;
        }
        return res;
    }
};
// @lc code=end

