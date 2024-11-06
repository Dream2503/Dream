/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (not (head and head->next and head->next->next)) return head;
        vector<int> even, odd;
        ListNode *current = head->next;

        while (current) {
            even.push_back(current->val);
            
            if (current = current->next) {
                odd.push_back(current->val);
                current = current->next;
            }
        }
        current = head->next;

        for (int num: odd) {
            current->val = num;
            current = current->next;
        }
        for (int num: even) {
            current->val = num;
            current = current->next;
        }
        return head;
    }
};
// @lc code=end

