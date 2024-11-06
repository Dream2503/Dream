/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m+n);
        int i = 0, j = 0, k = 0;

        while (i != m and j != n) {
            if (nums1[i] < nums2[j]) result[k++] = nums1[i++];
            else if (nums1[i] > nums2[j]) result[k++] = nums2[j++];
            else {
                result[k++] = nums1[i++];
                result[k++] = nums2[j++];
            }
        }
        for (; i < m; i++) result[k++] = nums1[i];
        for (; j < n; j++) result[k++] = nums2[j];
        nums1 = result;
    }
};
// @lc code=end

