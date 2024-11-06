/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        short length = s.length(), i = 0, cnt;
        bool is_palindrome = false;
        string big, x;
        big += s[0];

        while (i < length - big.length()) {
            for (short j = length - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    is_palindrome = true;
                    cnt = 1;

                    for (short k = i + 1; k < j; k++) {
                        if (s[k] == s[j - cnt])
                            is_palindrome = true;
                        else {
                            is_palindrome = false;
                            break;
                        }
                        cnt++;
                    }
                    if (is_palindrome) {
                        x = s.substr(i, j-i+1);

                        if (big.length() < x.length())
                            big = x;
                    }
                }
            }
            i++;
        }
        return big;
    }
};
// @lc code=end

