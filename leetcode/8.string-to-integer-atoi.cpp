/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        short sign = 1, i = 0;

        while (s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while (s[i] >= '0' and s[i] <= '9') {
            char digit = s[i] - '0';

            if (num > INT_MAX / 10 or (num == INT_MAX / 10 and digit > INT_MAX % 10)) {
                if (sign == 1) 
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            num = num * 10 + digit;
            i++;
        }
        return sign * num;
    }
};
// @lc code=end

