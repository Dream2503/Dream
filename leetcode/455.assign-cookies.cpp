/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        int i = 0, j = 0, gSize = g.size(), sSize = s.size();

        while (i < gSize and j < sSize) {
            if (g[i] <= s[j]) i++;
            j++;
        }
        return i;
    }
};
// @lc code=end

