/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size(), i = 2;

        if (not flowerbed[0] and size == 1) return true;
        if (not (flowerbed[0] or flowerbed[1])) {
            n--;
            flowerbed[0] = 1;
        }
        if (not (flowerbed[size-1] or flowerbed[size-2])) {
            n--;
            flowerbed[size-1] = 1;
        }
        size -= 2;

        for (; n and i < size; i++) {
            if (not flowerbed[i] and not flowerbed[i-1] and not flowerbed[i+1]) {
                n--;
                i++;
            }
        }
        return n < 1;
    }
};
// @lc code=end

