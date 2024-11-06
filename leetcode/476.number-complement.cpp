/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int cnt = 1, temp = num;
        while (temp = temp >> 1) cnt++;
        num = (~num) << (32 - cnt);
        return num >> (32 - cnt);
    }
};
// @lc code=end

