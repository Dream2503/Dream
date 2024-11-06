/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        for (char i = 0, size = s.size(); i < size; i++) s[i] = tolower(s[i]);
        return s;
    }
};
// @lc code=end

