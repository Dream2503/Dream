/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string> words) {
        vector<string> res, row({"eiopqrtuwy", "adfghjkls", "bcmnvxz"});
        string temp;
        int i, j, size;

        for (string word: words) {
            i = 1; j = 0;
            size = word.size();
            temp = word;
            transform(word.begin(), word.end(), word.begin(), [](char ch){ return tolower(ch);});
            sort(word.begin(), word.end());
                
            if (find(row[0].begin(), row[0].end(), word[0]) != row[0].end()) {
                while (i < size and j < 11) {
                    if (word[i] == row[0][j]) i++;
                    else j++;
                }
            } else if (find(row[1].begin(), row[1].end(), word[0]) != row[1].end()) {
                while (i < size and j < 10) {
                    if (word[i] == row[1][j]) i++;
                    else j++;
                }
            } else if (find(row[2].begin(), row[2].end(), word[0]) != row[2].end()) {
                while (i < size and j < 8) {
                    if (word[i] == row[2][j]) i++;
                    else j++;
                }
            }
            if (i == size) res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

