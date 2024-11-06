/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        
        for (int i = 0; i < 31; i++) {
            if ((x & 1) ^ (y & 1)) res++;
            x = x >> 1, y = y >> 1;
        }
        return res;
    }
};
// @lc code=end

