/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
private:
    bool in(char ch, string str) {
        short cnt = 0;
        char chr;

        while ((chr = str[cnt]) != '\0') {
            if (chr == ch)
                return true;
            cnt ++;
        }

        return false;
    }

public:
    int lengthOfLongestSubstring(string s) {
        short cnt = 0, shortLen = 0, longLen = 0, length = s.length();
        string shorter;

        while (cnt < (length - longLen)) {
            for (short idx = cnt; idx < length; idx++) {
                if (shorter.find(s[idx]) >= shortLen) {
                    shorter += s[idx];
                    shortLen++;
                } else
                    break;
            }
            if (longLen < shortLen)
                longLen = shortLen;
            
            shorter.clear();
            shortLen = 0;
            cnt++;
        }
        return longLen;
    }
};
// @lc code=end

