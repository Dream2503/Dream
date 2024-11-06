/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int array[26] = {0};
        for (char ch: s) array[ch-'a']++;
        for (char ch: t) array[ch-'a']--;
        for (int element: array) if (element) return false;
        return true;
    }
};
// @lc code=end

