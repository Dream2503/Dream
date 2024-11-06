/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
    vector<int> vec;
public:
    NumArray(vector<int>& nums) {vec = nums;}
    int sumRange(int left, int right) {
        int sum = 0;
        for (; left <= right; left++) sum += vec[left];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

