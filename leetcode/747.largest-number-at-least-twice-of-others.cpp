/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0, idx, size = nums.size();

        for (int i = 0; i < size; i++)
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        max /= 2;
        nums[idx] = -1;
        for (int i = 0; i < size; i++) if (nums[i] > max) return -1;
        return idx;
    }
};
// @lc code=end

