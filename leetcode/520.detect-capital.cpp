/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int i = 0, size = word.size() - 1;
        if (not size) return true;
        auto isUpper = [](char &ch) -> bool {return ch >= 'A' and ch <= 'Z';};
    
        if (isUpper(word[i])) {
            if (isUpper(word[++i])) while (i < size) {if (not isUpper(word[++i])) return false;}
            else while (i < size) {if (isUpper(word[++i])) return false;}
        } else while (i < size) if (isUpper(word[++i])) return false;
        return true;
    }
};
// @lc code=end

