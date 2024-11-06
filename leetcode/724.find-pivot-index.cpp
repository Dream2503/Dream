/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0, size = nums.size(), idx = 0;
        if (size == 1) return 0;
        for (int i = 1; i < size; i++) rightSum += nums[i];

        while (leftSum != rightSum and idx < size - 1) {
            leftSum += nums[idx++];
            rightSum -= nums[idx];
        }
        if (leftSum == rightSum) return idx;
        return -1;
    }
};
// @lc code=end

