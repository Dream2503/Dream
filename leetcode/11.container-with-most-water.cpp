/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, temp, i = 0, j = height.size() - 1;

        while (i < j) {
            temp = min(height[i], height[j]) * (j-i);
            if (temp > res) res = temp;
            height[i] < height[j] ? i++ : j--;
        }
        return res;
    }
};
// @lc code=end

