/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
    int checkBit(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) if ((n >> i) & 1) res += 1;
        return res;
    }
public:
    bool isPowerOfTwo(int n) {
        if ((n > 0 and checkBit(n) == 1)) return true;
        return false;
    }
};
// @lc code=end

