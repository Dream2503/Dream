/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (not nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0, size = nums.size(), save;

        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                save = i;

                while (i < size and nums[i] == val) {
                    cnt++;
                    i++;
                }
                nums.erase(nums.begin()+save, nums.begin()+save+cnt);
                return size - cnt;
            }
        }
        return size;
    }
};
// @lc code=end

