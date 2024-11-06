/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> res;

        for (ListNode *node: lists) {
            while (node) {
                res.push_back(node->val);
                node = node->next;
            }
        }
        if (not res.size()) return nullptr;
        sort(res.begin(), res.end());
        ListNode *head = new ListNode(res[0]), *current = head;
        
        for (int num: res) {
            current->next = new ListNode(num);
            current = current->next;
        }
        return head->next;
    }
};
// @lc code=end

