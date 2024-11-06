/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = nums[0], size = nums.size();

        for (int i = 1; i <= size; i++) {
            if (i < size and nums[i] == nums[i-1] + 1)continue;
            if (start == nums[i-1]) res.push_back(to_string(start));
            else res.push_back(to_string(start) + "->" + to_string(nums[i-1]));
            if (i < nums.size()) start = nums[i];
        }
        return res;
    }
};
// @lc code=end

