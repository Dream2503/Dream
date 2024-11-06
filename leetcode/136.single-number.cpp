/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 1; i += 2) {
            if (nums[i] != nums[i+1]) return nums[i];
        }
        return nums[size-1];
    }
};
// @lc code=end

