/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int res = 1, temp = res;
        unordered_set<int> seen;

        while (seen.size() != n) {
            while (true) {
                if (temp == 1 or seen.find(temp) != seen.end()) seen.insert(res);
                else {
                    if (temp % 2 == 0) temp /= 2;
                    else break;
                    if (temp % 3 == 0) temp /= 3;
                    else break;
                    if (temp % 5 == 0) temp /= 5;
                    else break;
                }
            }
            temp = ++res;
        }
        return --res;
    }
};
// @lc code=end

