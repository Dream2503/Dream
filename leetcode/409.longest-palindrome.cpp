/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        int cnt = 0, check = 0;
        for (char ch: s) hash[ch]++;

        for (auto element: hash) {
            if (element.second % 2 == 0) cnt += element.second;
            else if (not check) check = element.second;
            else {
                if (max(element.second, check) != check) cnt += --check;
                else cnt += --element.second;
                check = max(element.second, check);
            }
        }
        return cnt + check;
    }
};
// @lc code=end

