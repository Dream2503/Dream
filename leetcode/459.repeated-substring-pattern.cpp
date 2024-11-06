/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string trimmed = doubled.substr(1, doubled.size() - 2);
        return trimmed.find(s) != string::npos;
    }
};
// @lc code=end