/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0, size = nums.size() - 1, i = 0;
        sort(nums.begin(), nums.end());

        while (i < size) {
            if (nums[i] < nums[i+1]) res += nums[i];
            else res += nums[i+1];
            i += 2;
        }
        return res;
    }
};
// @lc code=end

