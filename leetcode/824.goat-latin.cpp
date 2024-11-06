/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        istringstream iss(sentence);
        string res, word, end = "maa";
        char x;
        auto isVowel = [](const char &ch) -> bool {return ch == 'a' or ch == 'e' or ch =='i' or ch == 'o' or ch == 'u';};

        while (not iss.eof()) {
            iss >> word;
            x = word[0];

            if (not isVowel(tolower(x))) {
                word.push_back(*word.begin());
                word.erase(word.begin());
            }
            word += end;
            end += 'a';
            res += word;
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
