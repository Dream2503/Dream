/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int size = points.size();
        for (int i = 0; i < size; i++) for (int j = i + 1; j < size; j++) for (int k = j + 1; k < size; k++) maxArea = max(maxArea, 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])));
        return maxArea;
    }
};

// @lc code=end

