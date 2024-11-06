/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(), res = (size1 + size2) / 2;;
        vector<int> mergeList(size1+size2);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), mergeList.begin());
        if ((size1 + size2) % 2 == 0) return (mergeList[res] + mergeList[res - 1]) / 2.0;
        else return mergeList[res];
    }
};
// @lc code=end

