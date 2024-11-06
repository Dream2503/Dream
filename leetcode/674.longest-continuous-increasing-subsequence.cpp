/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, current = 1, size = nums.size(), j;

        for (int i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (nums[j-1] < nums[j]) current++;
                else break;
            }
            i = j - 1;
            res = max(res, current);
            current = 1;
        }
        return res;
    }
};
// @lc code=end

