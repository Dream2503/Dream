/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream stream(s);
        string word;
        unordered_map<char,string> hash;
        
        for (char ch: pattern) {
            stream >> word;
            if (hash.find(ch) == hash.end()) {
                for (auto element: hash) if (element.second == word) return false;
                hash[ch] = word;
            }
            else if (hash[ch] != word) return false;
        }
        return stream.eof();
    }
};
// @lc code=end

