/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (not list1) return list2;
        if (not list2) return list1;
        ListNode *result = new ListNode, *current;

        if (list1->val < list2->val) {
            result->val = list1->val;
            list1 = list1->next;
        } else {
            result->val = list2->val;
            list2 = list2->next;
        }
        current = result;

        while (list1 and list2) {
            current->next = new ListNode;
            current = current->next;

            if (list1->val < list2->val) {
                current->val = list1->val;
                list1 = list1->next;
            } else if ( list1->val > list2->val) {
                current->val = list2->val;
                list2 = list2->next;
            } else {
                current->val = list1->val;
                list1 = list1->next;
                current->next = new ListNode;
                current = current->next;
                current->val = list2->val;
                list2 = list2->next;
            }
        }
        while (list1) {
            current->next = new ListNode;
            current = current->next;
            current->val = list1->val;
            list1 = list1->next;
        }
        while (list2) {
            current->next = new ListNode;
            current = current->next;
            current->val = list2->val;
            list2 = list2->next;
        }
        return result;
    }
};
// @lc code=end

