/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (not (head and head->next)) return head;
        ListNode *prev = head, *current = prev->next;
        int len = 1;
        while (prev = prev->next) len++;
        k %= len;
        prev = head;

        for (int i = 0; i < k; i++) {
            while (current->next) {
                prev = current;
                current = current->next;
            }
            prev->next = nullptr;
            current->next = head;
            head = current;
        }
        return head;
    }
};
// @lc code=end

