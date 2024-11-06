/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, size1 = nums1.size(), size2 = nums2.size();
        vector<int> res;

        while (i < size1 and j < size2) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                res.push_back(nums1[i++]);
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

