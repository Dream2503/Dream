/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if (not (head and head->next)) return head;
        ListNode *current = head, *res, *temp;
        bool onHead = true;
        
        while (current) {
            if (current->val < x) {
                if (onHead) {
                    res = new ListNode(current->val);
                    temp = res;
                    onHead = false;
                }
                else {
                    temp->next = new ListNode(current->val);
                    temp = temp->next;
                }
            }
            current = current->next;
        }
        current = head;

        while (current) {
            if (current->val >= x) {
                if (onHead) {
                    res = new ListNode(current->val);
                    temp = res;
                    onHead = false;
                }
                else {
                    temp->next = new ListNode(current->val);
                    temp = temp->next;
                }
            }
            current = current->next;
        }
        return res;
    }
};
// @lc code=end

