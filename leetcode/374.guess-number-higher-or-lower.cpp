/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long low = 1, high = INT_MAX, mid = (low + high) / 2;

        while (low <= high) {
            switch (guess(mid)) {
                case -1:
                    high = mid - 1;
                    break;
                
                case 1:
                    low = mid + 1;
                    break;
                
                case 0:
                    return mid;
            }
            mid = (low + high) / 2;
        }
        return 0;
    }
};
// @lc code=end

