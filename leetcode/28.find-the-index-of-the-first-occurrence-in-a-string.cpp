/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size(), size2 = needle.size(), ans;
        bool found = false;

        for (int i = 0; i < size1; i++) {
            if (haystack[i] == needle[0]) {
                ans = i;
                found = true;

                for (int j = 0, k = i; j < size2; j++, k++) {
                    if (k == size1 or haystack[k] != needle[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) return ans;
            }
        }
        return -1;
    }
};
// @lc code=end

