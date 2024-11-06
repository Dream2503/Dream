/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int size1 = img1.size(), res;
        vector<int> vec1, vec2;

        for (int i = 0; i < size1 *size1; i++) {
            res = i / size1 * (2 * size1 - 1) + i % size1;
            if (img1[i / size1][i % size1]) vec1.push_back(res);
            if (img2[i / size1][i % size1]) vec2.push_back(res);
        }
        res = 0;
        unordered_map<int,int> count;
        for (int cord1: vec1) for (int cord2: vec2) count[cord1 - cord2]++;
        for(auto element: count) res = max(res, element.second);
        return res;
    }
};
// @lc code=end

