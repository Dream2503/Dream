/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int old = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int news = nums.size(), i = 0, j = 1, k = 0;
        vector<int> res(old-news);

// [1, 2, 3, 4, 7, 8]

        while (i < news and j <= old) {
            if (nums[i] != j) {
                res[k] = j;
                j++; k++;
            } else {i++; j++;}
        }
        while (j <= old) {
            res[k] = j;
            j++; k++;
        }
        return res;
    }
};
// @lc code=end

