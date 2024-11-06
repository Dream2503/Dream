/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if (not (head and head->next)) return head;
        vector<int> vec;
        ListNode *current = head;

        while (current) {
            vec.push_back(current->val);
            current = current->next;
        }
        sort(vec.begin(), vec.end());
        current = head;

        for (int num: vec) {
            current->val = num;
            current = current->next;
        }
        return head;
    }
};
// @lc code=end

