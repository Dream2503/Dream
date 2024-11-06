/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right, sum, size = nums.size(), tol = INT_MAX, res; 

        for (int i = 0; i < size; i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            left = i + 1, right = size - 1;

            while (left < right) {
                sum = nums[left] + nums[right] + nums[i];
                if (abs(target - sum) < tol) {
                    tol = abs(target - sum);
                    res = sum;
                }
                if (sum == target) {left++; right--;}
                else if (sum < target) left++;
                else right--;
            }
        }
        return res;
    }
};
// @lc code=end

