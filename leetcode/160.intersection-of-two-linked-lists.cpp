/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> vec;

        while (headA or headB) {
            if (headA) {
                if (find(vec.begin(), vec.end(), headA) != vec.end()) return headA;
                vec.push_back(headA);
                headA = headA->next;
            } if (headB) {
                if (find(vec.begin(), vec.end(), headB) != vec.end()) return headB;
                vec.push_back(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

