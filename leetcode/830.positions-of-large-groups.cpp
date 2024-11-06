/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 0, j = 1, size = s.size();
        vector<vector<int>> res;

        while (j < size) {
            while (s[j] and s[j] == s[i]) j++;
            if (j - i > 2) res.push_back({i, j-1});
            i = j; j++;
        }
        return res;
    }
};
// @lc code=end

