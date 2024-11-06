/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<pair<char,string>> vec{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        unordered_map<char,string> hash(vec.begin(), vec.end());
        vector<string> res;
        int size = digits.size();
        string temp;

        if (size == 1) 
            for (char ch: hash[digits[0]]) {
                temp = ch;
                res.push_back(temp);
            }
        else if (size == 2) 
            for (char ch1: hash[digits[0]])
                for (char ch2: hash[digits[1]]) {
                    temp = ch1; temp += ch2;
                    res.push_back(temp);
                }
        else if (size == 3) 
            for (char ch1: hash[digits[0]])
                for (char ch2: hash[digits[1]])
                    for (char ch3: hash[digits[2]]) {
                        temp = ch1; temp += ch2; temp += ch3;
                        res.push_back(temp);
                    }
        else if (size == 4) 
            for (char ch1: hash[digits[0]])
                for (char ch2: hash[digits[1]])
                    for (char ch3: hash[digits[2]])
                        for (char ch4: hash[digits[3]]) {
                            temp = ch1; temp += ch2; temp += ch3; temp += ch4;
                            res.push_back(temp);
                        }
        return res;
    }
};
// @lc code=end

