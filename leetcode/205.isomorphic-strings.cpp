/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hash;
        
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < s.size(); i++) {
                if (hash.find(s[i]) == hash.end()) hash.insert({s[i], t[i]});
                else if (hash[s[i]] != t[i]) return false;
            }
            hash.clear();
            swap(s, t);
        }
        return true;
    }
};
// @lc code=end

