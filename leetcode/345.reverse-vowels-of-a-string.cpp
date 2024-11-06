/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
    bool isVowel(char ch) {return ch =='a' or ch =='e' or ch =='i' or ch =='o' or ch =='u' or ch =='A' or ch =='E' or ch =='I' or ch =='O' or ch =='U';}
public:
    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;
        char temp;
        
        while (low <= high) {
            if (not isVowel(s[low])) low++;
            else if (not isVowel(s[high])) high--;
            else {
                temp = s[low];
                s[low++] = s[high];
                s[high--] = temp;
            }
        }
        return s;
    }
};
// @lc code=end

