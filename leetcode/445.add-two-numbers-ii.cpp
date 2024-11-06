/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* reverse(ListNode *head) {
        if (not head->next) return head;
        ListNode *end = nullptr, *prev = head, *current = prev->next;

        while (current) {
            prev->next = end;
            end = prev;
            prev = current;
            current = current->next;
        }
        prev->next = end;
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = this->reverse(l1), l2 = this->reverse(l2);
        int sum = l1->val + l2->val, carry = sum / 10;
        ListNode *res = new ListNode(sum % 10), *current = res;
        l1 = l1->next, l2 = l2->next;

        while (l1 and l2) {
            sum = l1->val + l2->val + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next, l1 = l1->next, l2 = l2->next;
        }
        while (l1) {
            sum = l1->val + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next, l1 = l1->next;
        }
        while (l2) {
            sum = l2->val + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next, l2 = l2->next;
        }
        if (carry) current->next = new ListNode(carry);
        res = this->reverse(res);
        return res;
    }
};
// @lc code=end

