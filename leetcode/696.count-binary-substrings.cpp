/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, current = 1, cnt = 0, size = s.size();
        
        for (int i = 1; i < size; i++) {
            if (s[i] == s[i-1]) {
                current++;
            } else {
                cnt += min(prev, current);
                prev = current;
                current = 1;
            }
        }
        return cnt + min(prev, current);
    }
};
// @lc code=end

