/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (not (head and head->next)) return nullptr;
        vector<ListNode*> seen;

        while (head) {
            if (find(seen.begin(), seen.end(), head) != seen.end()) return head;
            seen.push_back(head);
            head = head->next;
        }
        return nullptr;
    }
};
// @lc code=end

