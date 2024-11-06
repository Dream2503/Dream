/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;

        for (int element: nums) {
            if (hash.find(element) != hash.end()) hash[element] += 1;
            else hash[element] = 1;
        }
        for (pair<int,int> element: hash) if (element.second > nums.size() / 2) return element.first;
        return 0;
    }
};
// @lc code=end

