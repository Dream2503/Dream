/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0, cnt = 0;
        unordered_set<int> primes({2, 3, 5, 7, 11, 13, 17, 19});

        for (; left <= right; left++) {
            for (int i = 0; i < 20; i++) if ((left >> i) & 1) cnt++;
            if (primes.find(cnt) != primes.end()) res++;
            cnt = 0;
        }
        return res;
    }
};
// @lc code=end

