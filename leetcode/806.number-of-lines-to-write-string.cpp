/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> res(2, 0);
        
        for (char ch: s)
            if ((res[1] += widths[ch-'a']) > 100) {
                res[1] = widths[ch-'a'];
                res[0]++;
            }
        res[0]++;
        return res;
    }
};
// @lc code=end

