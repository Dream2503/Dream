/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0]) return 0;
        int size = nums.size() - 1;
        for (int i = 0; i < size; i++) if (nums[i] + 1 != nums[i+1]) return nums[i] + 1;
        if (nums[size] != size + 1) return size + 1;
        return 0;
    }
};
// @lc code=end

