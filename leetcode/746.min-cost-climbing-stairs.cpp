/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int res = 0, size = cost.size();

        for (int i = 2; i < size; i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[size-1], cost[size-2]);
    }
};
// @lc code=end

