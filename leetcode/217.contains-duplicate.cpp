/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(nums.begin(), unique(nums.begin(), nums.end()));
        return nums.size() != res.size();
    }
};
// @lc code=end

