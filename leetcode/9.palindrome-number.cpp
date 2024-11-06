/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string res = to_string(x);
        for (int i = 0, j = res.size() - 1; i <= j; i++, j--) if (res[i] != res[j]) return false;
        return true;
    }
};
// @lc code=end

