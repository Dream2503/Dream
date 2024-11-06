/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_map<int,int> dict;
        int size = arr.size();

        for (int i = 0; i < size; i++) {
            if (dict.find(arr[i]) != dict.end()) if (abs(i-dict[arr[i]]) <= k) return true;
            dict[arr[i]] = i;
        }
        return false;
    }
};
// @lc code=end

