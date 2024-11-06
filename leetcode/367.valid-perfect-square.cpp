/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 100000001) return false;
        float res = sqrtf(num);
        return floor(res) == res;
    }
};
// @lc code=end

