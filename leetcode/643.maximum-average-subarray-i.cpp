/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res, sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        res = sum;
        int size = nums.size();

        for (int i = k; i < size; i++) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};

// @lc code=end

