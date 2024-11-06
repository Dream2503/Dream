/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long int size = nums.size(), sum = 0, expectedSum = size * (size + 1) / 2;
        long long int sumOfSquares = 0, expectedSumOfSquares = size * (size + 1) * (2 * size + 1) / 6;
        
        for (int num : nums) {
            sum += num;
            sumOfSquares += num * num;
        }
        long long int diffSum = expectedSum - sum, diffSquareSum = expectedSumOfSquares - sumOfSquares, sumDiff = diffSquareSum / diffSum;
        int missing = (diffSum + sumDiff) / 2, duplicate = sumDiff - missing;
        return {duplicate, missing};
    }
};
// @lc code=end

