/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size(), i, j, k;
        bool flag;

        for (i = 0; i < 2; i++) {
            for (j = i + 1, k = i; j < size; j++) if (nums[j] < nums[k]) k = j;
            swap(nums[i], nums[k]);
        }
        for (int i = 1; i < 4; i++) {
            flag = false;

            for (j = 0; j < size - i; j++) {
                if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
                flag = true;
            }
            if (not flag) break;
        }

        int num1 = nums[size-1] * nums[size-2] * nums[size-3], num2 = nums[0] * nums[1] * nums[size-1];
        return max(num1, num2);
    }
};
// @lc code=end

