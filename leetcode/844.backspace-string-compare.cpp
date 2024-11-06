/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S, T;
        
        for (char ch: s) {
            if (ch == '#' and not S.empty()) S.pop_back();
            else if (ch != '#') S.push_back(ch);
        }
        for (char ch: t) {
            if (ch == '#' and not T.empty()) T.pop_back();
            else if (ch != '#') T.push_back(ch);
        }
        return S == T;
    }
};
// @lc code=end

