/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (auto num = digits.end() - 1; num != digits.begin() - 1; num--) {
            if (*num == 9) {
                *num = 0;
                carry = 1;
            } else {
                *num += carry;
                carry--;
                break;
            }
        }
        if (carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};
// @lc code=end

