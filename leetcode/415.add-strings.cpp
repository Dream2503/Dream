/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0, add;

        if (i < j) {
            swap(num1, num2);
            swap(i, j);
        }
        while (j != -1) {
            add = num1[i] + num2[j] - 96 + carry;
            carry = add / 10;
            num1[i] = (add % 10) + 48;
            i--; j--;
        }
        while (carry and i != -1) {
            add = num1[i] + carry - 48;
            carry = add / 10;
            num1[i] = (add % 10) + 48;
            i--;
        }
        if (carry) num1.insert(num1.begin(), carry + 48);
        return num1;
    }
};
// @lc code=end

