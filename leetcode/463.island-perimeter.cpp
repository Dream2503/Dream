/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), i, j, perimeter = 0;

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j]) {
                    if (i - 1 < 0 or not grid[i-1][j]) perimeter++;
                    if (i + 1 == row or not grid[i+1][j]) perimeter++;
                    if (j - 1 < 0 or not grid[i][j-1]) perimeter++;
                    if (j + 1 == col or not grid[i][j+1]) perimeter++;
                }
            }
        }
        return perimeter;
    }
};
// @lc code=end

