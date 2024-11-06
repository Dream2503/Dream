/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next, *prev;

        while (next) {
            node->val = next->val;
            prev = node;
            node = next;
            next = next->next;
        }
        prev->next = nullptr;
    }
};
// @lc code=end

