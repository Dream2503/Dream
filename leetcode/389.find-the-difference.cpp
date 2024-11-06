/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int array[26] = {0};
        for (char ch: t) array[ch-'a']++;
        for (char ch: s) array[ch-'a']--;
        for (int i = 0; i < 26; i++) if (array[i] == 1) return 'a' + i;
        return 0;
    }
};
// @lc code=end

