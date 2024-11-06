/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> words) {
        string chs;
        for (char ch: licensePlate) if (ch >= 'A') chs += tolower(ch);
        sort(chs.begin(), chs.end());
        int i = 0, j = 0, cnt = 0, size = words.size(), size1, size2 = chs.size(), minSize = 10e3, res = 0;
        string temp;

        for (int k = 0; k < size; k++) {
            temp = words[k];
            sort(temp.begin(), temp.end());
            size1 = temp.size();

            while (i < size1 and j < size2) {
                if (temp[i] < chs[j]) i++;
                else if (temp[i] > chs[j]) j++;
                else {i++; j++; cnt++;}
            }
            if (cnt == size2) if (minSize > size1) {
                res = k;
                minSize = size1;
            }
            i = 0; j = 0; cnt = 0;
        }
        return words[res];
    }
};
// @lc code=end

