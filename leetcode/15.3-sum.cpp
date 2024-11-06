/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int left, right, target, sum, size = nums.size();

        for (int i = 0; i < size; i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            left = i + 1, right = size - 1, target = -nums[i];

            while (left < right) {
                sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right and nums[left] == nums[left + 1]) left++;
                    while (left < right and nums[right] == nums[right - 1]) right--;
                    left++; right--;
                } else if (sum < target) left++;
                else right--;
            }
        }
        return result;
    }
};
// @lc code=end

