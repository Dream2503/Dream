/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, size = bits.size();
        while (i < size - 1) i += 1 + bits[i];
        return i != size;
    }
};
// @lc code=end

