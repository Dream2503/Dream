/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int idx1 = 0, idx2 = 0, cnt = 1, size = s.size();
        vector<int> res(size, 0);
        while (s[idx1] != c) idx1++;
        for (int i = idx1 - 1; i > -1; i--) res[i] = cnt++;
        
        while (s[idx2]) {
            cnt = 1;
            idx2 = idx1 + 1;
            while (s[idx2] and s[idx2] != c) idx2++;
            if (not s[idx2]) break;
            for (int i = idx1 + 1, j = idx2 - 1; i <= j; i++, j--) res[i] = res[j] = cnt++;
            idx1 = idx2;
        }
        cnt = 1;
        for (int i = idx1 + 1; s[i]; i++) res[i] = cnt++;
        return res;
    }
};
// @lc code=end

