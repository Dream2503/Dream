/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int temp;
        bool divisible = true;
        while (left < 10) res.push_back(left++);

        for (temp = left; left <= right; temp = ++left ) {    
            while (temp) {
                if (not (temp % 10) or (left % (temp % 10))) {
                    divisible = false;
                    break;
                }
                temp /= 10;
            } if (divisible) res.push_back(left);
            else divisible = true;
        }
        return res;
    }
};
// @lc code=end

