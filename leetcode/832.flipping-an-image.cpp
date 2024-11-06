/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> image) {
        for (vector<int> &row: image) {
            reverse(row.begin(), row.end());
            transform(row.begin(), row.end(), row.begin(), [](int &num){return not num;});
        }
        return image;
    }
};
// @lc code=end

