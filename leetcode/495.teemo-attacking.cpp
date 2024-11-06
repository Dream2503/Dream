/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int cnt = 0, temp, size = timeSeries.size() - 1;
        if (not size) return duration;

        for (int i = 0; i < size; i++) {
            temp = timeSeries[i] + duration - 1;
            cnt += duration;
            if (temp >= timeSeries[i+1]) 
                cnt -= temp - timeSeries[i+1] + 1;  
        }
        return cnt + duration;
    }
};
// @lc code=end

