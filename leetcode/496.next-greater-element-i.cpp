/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
        int size1 = nums1.size(), i, j, check;
        bool found = false;
        vector<int>::iterator it;

        for (i = 0; i < size1; i++) {
            it = find(nums2.begin(), nums2.end(), nums1[i]);
            check = *it;

            for (it++; it != nums2.end(); it++) if (check < *it) {
                found = true;
                break;
            }
            if (found) nums1[i] = *it;
            else nums1[i] = -1;
            found = false;
        }
        return nums1;
    }
};
// @lc code=end

