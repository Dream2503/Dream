/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (not head->next) return true;
        vector<int> res;

        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        vector<int> rev(res.size());
        reverse_copy(res.begin(), res.end(), rev.begin());
        return res == rev;
    }
};
// @lc code=end

