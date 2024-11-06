/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *current = head, *prev;
        int len = 0;

        while (current) {
            len++;
            current = current->next;
        }
        current = head;
        vector<ListNode*> res(k, nullptr);

        if (len > k) {
            int rem = len % k, size = len / k, overHead;

            for (int i = 0; i < k; i++) {
                res[i] = current;

                if (rem) {
                    overHead = 1;
                    rem--;
                }
                else overHead = 0;

                for (int j = 0; j < size + overHead; j++) {
                    prev = current;
                    current = current->next;
                }
                prev->next = nullptr;
            }
        } else {
            int i = 0;

            while (current) {
                res[i] = current;
                i++;
                prev = current;
                current = current->next;
                prev->next = nullptr;
            }
        }
        return res;
    }
};
// @lc code=end

