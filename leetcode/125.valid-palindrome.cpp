/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
    char convert(char &ch) {
        if (ch >= '0' and ch <= '9') return 'a';
        if (ch >= 'A' and ch <= 'Z')  ch += ' ';
        return ch;
    }

public:
    bool isPalindrome(string s) {
        char check;

        for (int i = 0, j = s.size() - 1; i <= j;) {
            if (not (convert(s[i]) >= 'a' and s[i] <= 'z')) {i++; continue;}
            if (not (convert(s[j]) >= 'a' and s[j] <= 'z')) {j--; continue;}
            check = s[i] - s[j];
            if (check) return false;
            i++, j--;
        }
        return true;
    }
};
// @lc code=end

