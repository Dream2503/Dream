/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        a.insert(a.begin(), 0);
        b.insert(b.begin(), 0);
        auto ch1 = a.end() - 1, ch2 = b.end() - 1;
        int temp, carry = 0;

        for (; *ch1 and *ch2; ch1--, ch2--) {
            temp = (*ch1 - '0') + (*ch2 - '0') + carry;
            carry = 0;

            if (temp == 2) {
                carry = 1;
                res.insert(res.begin(), '0');
            } else if (temp == 3) {
                carry = 1;
                res.insert(res.begin(), '1');
            } else res.insert(res.begin(), (char)(temp+'0'));
        }
        for (; *ch1; ch1--) {
            temp = *ch1 - '0' + carry;
            carry = 0;

            if (temp == 2) {
                carry = 1;
                res.insert(res.begin(), '0');
            } else res.insert(res.begin(), (char)(temp+'0'));
        }
        for (; *ch2; ch2--) {
            temp = *ch2 - '0' + carry;
            carry = 0;

            if (temp == 2) {
                carry = 1;
                res.insert(res.begin(), '0');
            } else res.insert(res.begin(), (char)(temp+'0'));
        }
        if (carry) res.insert(res.begin(), (char)(carry+'0'));
        return res;
    }
};
// @lc code=end

