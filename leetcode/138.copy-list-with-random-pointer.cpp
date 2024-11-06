/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (not head) return nullptr;
        unordered_map<Node*,Node*> hash;
        Node *res = new Node(head->val), *current1 = head->next, *current2 = res;
        hash[head] = res;
        
        while (current1) {
            current2->next = new Node(current1->val);
            current2 = current2->next;
            hash[current1] = current2;
            current1 = current1->next;
        }
        current1 = head, current2 = res;

        while (current1) {
            current2->random = hash[current1->random];
            current1 = current1->next;
            current2 = current2->next;
        }
        return res;
    }
};
// @lc code=end

