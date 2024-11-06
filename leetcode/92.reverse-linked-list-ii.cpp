/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (not head->next) return head;
        vector<int> res;
        left--;

        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin()+left, res.begin()+right);
        head = new ListNode(res[0]);
        ListNode *current = head;
    
        for (int num: res) {
            current->next = new ListNode(num);
            current = current->next;
        }
        return head->next;
    }
};
// @lc code=end

