/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool started = false;
        int res = 0;

        for (auto ch = s.end() - 1; ch != s.begin() - 1; ch--) {
            if (*ch == ' ' and (not started)) continue;
            else if (*ch == ' ') break;
            else if (*ch != ' ') {
                started = true;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

