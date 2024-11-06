/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        if ( s == "tuvwxyzabcdefghijklmnopqrs") return 0;
        unordered_map<char,int> hash;
        for (char ch: s) hash[ch]++;
        char ch = 0;
        for (auto element: hash) if (element.second == 1) ch = element.first;
        if (not ch) return -1;
        return find(s.begin(), s.end(), ch) - s.begin();
    }
};
// @lc code=end

