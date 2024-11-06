/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        short length = s.length(), cnt = 0;
        bool next = true;
        string *array[numRows];

        if (numRows == 1)
            return s;
        
        for (short i = 0; i < numRows; i++) 
            array[i] = new string;
        
        for (int ch_idx = 0; ch_idx < length; ch_idx++) {
            if (next) {
                *array[cnt] += s[ch_idx];
                cnt += 1;

                if (cnt < numRows)
                    continue;
                else {
                    next = false;
                    cnt -= 2;
                }
            } else {
                *array[cnt] += s[ch_idx];
                cnt -= 1;

                if (cnt >= 0)
                    continue;
                else
                    next = true;
                    cnt += 2;
            }
        }
        for (int i = 1; i < numRows; i++)
            array[0]->append(*array[i]);

        return *array[0];
    }
};
// @lc code=end

