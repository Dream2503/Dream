/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int array[2] = {0, 0};

        for (char ch: moves) switch (ch) {
            case 'R':
                array[0]++;
                break;

            case 'L':
                array[0]--;
                break;
            
            case 'U':
                array[1]++;
                break;

            case 'D':
                array[1]--;
                break;
        }
        return not (array[0] or array[1]);
    }
};
// @lc code=end

