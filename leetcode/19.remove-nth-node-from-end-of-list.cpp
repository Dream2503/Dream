/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *current = head->next, *prev = head;

        while (prev) {
            cnt++;
            prev = prev->next;
        }
        cnt -= n;
        prev = head;

        if (cnt == 0) return head->next;

        for (int i = 1; i < cnt; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        return head;
    }
};
// @lc code=end

