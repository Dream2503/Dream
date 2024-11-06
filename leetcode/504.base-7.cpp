/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool isNegative = num < 0;
        if (isNegative) num = -num;
        string res;

        while (num > 0) {
            res += (num % 7) + '0';
            num /= 7;
        }
        if (isNegative) res += '-';
        
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

