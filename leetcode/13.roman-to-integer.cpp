/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
       int res = 0, size = s.size();
        vector<pair<char,int>> vec{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        unordered_map<char,int> hash(vec.begin(), vec.end());

        for (int idx = 0; idx < size; idx++) {
            if ((idx + 1 < size) and ((s[idx] == 'I' and (s[idx + 1] == 'V' or s[idx + 1] == 'X')) or (s[idx] == 'X' and (s[idx + 1] == 'L' or s[idx + 1] == 'C')) or (s[idx] == 'C' and (s[idx + 1] == 'D' or s[idx + 1] == 'M')))) res -= hash[s[idx]];
            else res += hash[s[idx]];
        }
        return res;
    }
};
// @lc code=end

