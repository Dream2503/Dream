/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int left, right, sum, size = nums.size();
        long tar;

        for (int i = 0; i < size; i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < size; j++) {
                if (j > i + 1 and nums[j] == nums[j - 1]) continue;
                left = j + 1, right = size - 1, tar = target - (long)nums[i] - (long)nums[j];

                while (left < right) {
                    sum = nums[left] + nums[right];

                    if (sum == tar) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right and nums[left] == nums[left + 1]) left++;
                        while (left < right and nums[right] == nums[right - 1]) right--;
                        left++; right--;
                    } else if (sum < tar) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

