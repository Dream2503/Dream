/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (not head->next) return head;
        vector<int> vec;
        
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, size = vec.size() - k; i <= size; i += k) reverse(vec.begin()+i, vec.begin()+i+k);
        head = new ListNode(vec[0]);
        ListNode *current = head;

        for (int num: vec) {
            current->next = new ListNode(num);
            current = current->next;
        }
        return head->next;
    }
};
// @lc code=end

