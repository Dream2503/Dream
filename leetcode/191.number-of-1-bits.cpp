/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        for (int i = 0; i < 31; i++) res += (n >> i) & 1;
        return res;
    }
};
// @lc code=end

