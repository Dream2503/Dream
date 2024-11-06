/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int i = 0, size = s.size(), cnt = 0;
        while (i < size and s[i] == ' ') i++;

        while (i < size) {
            cnt++;
            while (i < size and s[i] != ' ') i++;
            while (i < size and s[i] == ' ') i++;
        }
        return cnt;
    }
};
// @lc code=end

