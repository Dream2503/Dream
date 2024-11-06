/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, i = 0, j, size = nums.size();

        while (i < size) {
            if (nums[i]) {
                j = i;

                while (j < size) {
                    if (nums[j]) j++;
                    else break;
                }
                if ((j - i) > max) max = j - i;
                i = j;
            }
            i++;
        }
        return max;
    }
};
// @lc code=end

