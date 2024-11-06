/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i = 0, j = 0, og, size = s.size();
        while (s[i] == goal[j] and i < size) {i++; j++;}
        og = i;
        while (s[i] != goal[j] and i < size) i++;
        swap(s[og], s[i]);
        return s == goal and og != i;
    }
};
// @lc code=end

