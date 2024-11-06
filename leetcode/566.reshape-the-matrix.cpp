/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> mat, int r, int c) {
        int m = mat.size(), n = mat[0].size(), k = 0, l = 0;
        if ((r == m and c == n) or (r * c != m * n)) return mat;
        vector<vector<int>> res(r);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[k].push_back(mat[i][j]);
                if (++l == c) {
                    l = 0;
                    k++;
                } 
            }
        }
        return res;
    }
};
// @lc code=end

