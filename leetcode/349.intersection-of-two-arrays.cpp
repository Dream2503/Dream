/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, size1 = nums1.size(), size2 = nums2.size();
        unordered_set<int> seen;

        while (i < size1 and j < size2) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                seen.insert(nums1[i++]);
                j++;
            }
        }
        vector<int> res(seen.begin(), seen.end());
        return res;
    }
};
// @lc code=end

