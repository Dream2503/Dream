/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs[0].size(), pos = 0;
        char ch;

        while (n) {
            ch = strs[0][pos];
            for (string element: strs) if (ch != element[pos]) return res;
            res += ch;
            pos++;
            n--;
        }
        return res;
    }
};
// @lc code=end