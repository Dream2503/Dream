/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (not (head and head->next)) return head;
        unordered_map<int,int> hash;
        vector<int> res;
        
        while (head) {
            hash[head->val]++;
            head = head->next;
        }
        for (auto element: hash) if (element.second == 1) res.push_back(element.first);
        if (res.size() == 0) return nullptr;
        sort(res.begin(), res.end());
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

