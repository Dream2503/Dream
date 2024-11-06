/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = 0, size = nums.size();
        if (size == 1) return nums[0] == target ? 0 : -1;
        for (; nums[idx] < nums[idx + 1] and idx < size - 1; idx++);
        int low = 0, act_low = ++idx, high = size - 1, act_high = idx - 1, mid, act_mid, temp;

        do {
            temp = low + high;
            mid = temp / 2;
            act_mid = temp % 2 ? (mid) - idx : (mid) - idx + 1;
            if (act_mid >= size) act_mid -= size;
            if (act_mid < 0) act_mid += size;
            if (act_low >= size) act_low -= size;
            if (act_high < 0) act_high += size;
            if (nums[act_mid] == target) return act_mid;
            else if (nums[act_mid] > target) {
                act_high = act_mid - 1;
                high = mid - 1;
            } else {
                act_low = act_mid + 1;
                low = mid + 1;
            }
        }

    }
};
// @lc code=end

