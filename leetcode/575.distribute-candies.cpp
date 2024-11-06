/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> res(candyType.begin(), candyType.end());
        return min(res.size(), candyType.size() / 2);
    }
};
// @lc code=end

