/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (not (head and head->next)) return;
        ListNode *current = head;
        vector<int> vec;

        while (current) {
            vec.push_back(current->val);
            current = current->next;
        }
        int i = 1, j = vec.size() - 1;
        head->val = vec[0];
        current = head->next;

        while (i < j) {
            current->val = vec[j];
            current = current->next;
            current->val = vec[i];
            current = current->next;
            i++, j--;
        }
        if (vec.size() % 2 == 0) current->val = vec[i];
    }
};
// @lc code=end

