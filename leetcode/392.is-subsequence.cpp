/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, size = s.size(), tize = t.size();
        
        while (i < size and j < tize) {
            if (s[i] == t[j]) i++;
            j++;
        }
        if (i < size) return false;
        return true;
    }
};
// @lc code=end

