/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (not nums[i]) {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                size--; i--;
            }
        }
    }
};
// @lc code=end

