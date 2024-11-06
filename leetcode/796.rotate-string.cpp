/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0, j = 0, k;
        bool broke = false;
        if (s.size() != goal.size()) return false;

        while (true) {
            while (s[i] and s[i] != goal[j]) i++;
            if (not s[i]) return false;
            k = i;

            while (goal[j]) {
                if (s[i]) {
                    if (s[i++] != goal[j++]) {
                        broke = true;
                        break;
                    }
                } else i = 0;
            }
            if (not broke) return true;
            broke = false;
            i = k + 1; j = 0;
        }
        return false;
    }
};
// @lc code=end

