/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, size = s.size();

        while (j < size) {
            while (j < size and s[j] != ' ') j++;
            reverse(s.begin()+i, s.begin()+j);
            i = ++j;
        }
        return s;
    }
};
// @lc code=end

