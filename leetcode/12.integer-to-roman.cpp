/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,char>> vec{{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        unordered_map<int,char> hash(vec.begin(), vec.end());
        string res, temp;
        int unit, factor = 1;

        while (num) {
            temp = "";
            unit = (num % 10);
            num /= 10;

            if (unit < 5) {
                if (unit == 4) {
                    temp += hash[5*factor];
                    temp += hash[factor];
                } else for (int i = 1; i <= unit; i++) temp += hash[factor];
            } else if (unit > 5) {
                if (unit == 9) {
                    temp += hash[10*factor];
                    temp += hash[factor];
                } else {
                    for (int i = 1; i <= unit - 5; i++) temp += hash[factor];
                    temp += hash[5*factor];
                }
            } else temp += hash[unit*factor];
            res += temp;
            factor *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

