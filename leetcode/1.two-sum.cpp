/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int size = nums.size();

            for (int i = 0; i < size; i++) 
                for (int j = i+1; j < size; j++)
                    if (nums[i] + nums[j] == target)
                        return {i, j};
            
            return {};
        }
};
// @lc code=end

