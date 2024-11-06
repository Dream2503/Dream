/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        stringstream ss;
        ss << hex << num;
        return ss.str();
    }
};
// @lc code=end

