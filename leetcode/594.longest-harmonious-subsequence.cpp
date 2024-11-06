/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> hash;
        for (int num: nums) hash[num]++;
        vector<pair<int,int>> vec(hash.begin(), hash.end());
        int size = vec.size(), res = 0;
        for (int i = 0; i + 1 < size; i++) if (abs(vec[i].first - vec[i+1].first) == 1) res = max(res, vec[i].second + vec[i+1].second);
        return res;
    }
};
// @lc code=end

