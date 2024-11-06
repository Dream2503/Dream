/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (not (head and head->next)) return head;
        ListNode *end = nullptr, *prev = head, *current = prev->next;

        while (current) {
            prev->next = end;
            end = prev;
            prev = current;
            current = current->next;
        }
        prev->next = end;
        return prev;
    }
};
// @lc code=end

