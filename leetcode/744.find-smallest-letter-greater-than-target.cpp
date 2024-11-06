/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size(), low = 0, high = size - 1, mid;
        bool broke = false;

        while (low <= high) {
            mid = (low + high) / 2;
            if (letters[mid] < target) low = mid + 1;
            else if (letters[mid] > target) high = mid - 1;
            else {
                broke = true;
                break;
            }
        }
        if (not broke) mid = low;
        while (mid < size and letters[mid] == target) mid++;
        if (mid < size) return letters[mid];
        return letters[0];
    }
};
// @lc code=end

