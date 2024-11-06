/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        bool neg = expression[0] == '-';
        int i = neg ? 1: 0;
        char num1 = expression[i++], dec1 = expression[++i], opr = expression[i++], num2, dec2;

        for (; i < size; i++) {
            num2 = expression[i++], dec2 = expression[++i];
            if (dec1 == dec2) {
                if (opr == '+') num1 += neg ? -(num2 - '0'): num2 - '0';
                else num1 += neg ? : ;
            }
        }
    }
};
// @lc code=end

