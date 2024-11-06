/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        int array[26] = {0};
        for (char ch: ransomNote) array[ch-'a']++;
        for (char ch: magazine) array[ch-'a']--;
        for (int element: array) if (element > 0) return false;
        return true;
    }
};
// @lc code=end

