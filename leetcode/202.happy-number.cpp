/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int sum, digit;

        while (n != 1 and seen.find(n) == seen.end()) {
            seen.insert(n);
            sum = 0;
            
            while (n > 0) {
                digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
// @lc code=end

