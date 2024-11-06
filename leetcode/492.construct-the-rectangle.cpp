/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        if (area == 1) return {1, 1};
        vector<int> factors;
        area = (long long)area;

        for (int i = 1; i <= (int)sqrt(area); i++) {
            if (area % i == 0) {
                factors.push_back(i);
                if (i != area / i) factors.push_back(area / i);
            }
        }
        sort(factors.begin(), factors.end());
        int size = factors.size(), i = size / 2, j = i;
        if (size == 2) {
            return {factors[1], factors[0]};
        }

        while (i > 0 and j < size) {
            if ((long long)factors[i] * factors[j] < area) j++;
            else if ((long long)factors[i] * factors[j] > area) i--;
            else return {factors[j], factors[i]};
        }
        return {};
    }
};
// @lc code=end

