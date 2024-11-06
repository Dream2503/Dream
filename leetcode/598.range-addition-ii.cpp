/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m * n;
        int row = 4 * 10e4, column = 4 * 10e4;

        for (vector<int> &element: ops) {
            row = min(row, element[0]);
            column = min(column, element[1]);
        }
        return row * column;
    }
};
// @lc code=end

