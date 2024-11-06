/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (not (head and head->next)) return head;
        ListNode *end = nullptr, *prev = head, *current = prev->next;
        head = current;

        while (current) {
            prev->next = current->next;
            current->next = prev;
            if (end) end->next = current;
            end = prev;
            prev = prev->next;
            if (prev) current = prev->next;
            else break;
        }
        return head;
    }
};
// @lc code=end

