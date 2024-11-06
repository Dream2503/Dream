/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;

        while (true) {
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            if (sum < 10) return sum;
            num = sum;
            sum = 0;
        }
        return 0;
    }
};
// @lc code=end

