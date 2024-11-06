/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> hash;
        int res = 0;
        for (char ch: stones) hash[ch]++;
        for (char ch: jewels) res += hash[ch];
        return res;
    }
};
// @lc code=end

