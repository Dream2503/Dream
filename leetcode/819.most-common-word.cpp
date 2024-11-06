/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        istringstream iss(paragraph);
        string temp, word;
        char x;
        unordered_map<string,int> hash;
        
        while (not iss.eof()) {
            iss >> temp;
            for (char ch: temp) {
                if ((x = tolower(ch)) >= 'a' and x <= 'z') word += x;
                else if (not word.empty()) {
                    hash[word]++;
                    word.clear(); 
                }
            }
            if (not word.empty()) {
                hash[word]++;
                word.clear(); 
            }
        }
        auto cmp = [](const pair<string,int>& a, const pair<string,int>& b) -> bool {return a.second > b.second;};
        multiset<pair<string,int>, decltype(cmp)> list(hash.begin(), hash.end(), cmp);
        set<string> ban(banned.begin(), banned.end());
        for (auto &element: list) if (ban.find(element.first) == ban.end()) return element.first;
        return "";
    }
};
// @lc code=end

