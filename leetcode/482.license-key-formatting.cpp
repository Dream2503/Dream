/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int size = 0;
        for (char ch: s) if (ch != '-') size++;
        int first = size % k, i = 0, j = 0;
        ostringstream oss;

        while (j < first) {
            if (s[i] != '-') {
                oss << (char)toupper(s[i]);
                j++;
            }
            i++;
        }
        if (j) oss << '-';

        while (s[i]) {
            j = 0;

            while (j < k) {
                if (not s[i]) break;
                if (s[i] != '-') {
                    oss << (char)toupper(s[i]);
                    j++;
                }
                i++;
            }
            oss << '-';
        }
        string res = oss.str();
        while (*(res.end() - 1) == '-') res.pop_back();
        return res;
    }
};
// @lc code=end

