/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
         unordered_map<int,int> hash;
        for (int num: nums) hash[num]++;
        vector<pair<int,int>> vec(hash.begin(), hash.end());
        int size1 = nums.size(), size2 = vec.size(), i, j, k, check, res = 10e6;
    
        for (i = 0; i < size2 - 1; i++) {
            for (j = i + 1, k = i; j < size2; j++) if (vec[j].second > vec[k].second) k = j;
            swap(vec[i], vec[k]);
            if (i > 0) if (vec[i].second != vec[i-1].second) break;
        }
        check = (vec[0].second == vec[i].second) ? i + 1 : i;

        for (k = 0; k < check; k++) {
            for (i = 0; i < size1; i++) if (nums[i] == vec[k].first) break;
            for (j = size1 - 1; j > -1; j--) if (nums[j] == vec[k].first) break;
            res = min(res, j - i + 1);
        }
        return res;
    }
};
// @lc code=end

