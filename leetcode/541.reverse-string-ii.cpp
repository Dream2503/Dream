/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, size = s.size();

        while (i < size) {
            if (i + k - 1 < size) reverse(s.begin()+i, s.begin()+i+k);   
            else reverse(s.begin()+i, s.end());
            i += 2 * k;
        }
        return s;
    }
};
// @lc code=end

