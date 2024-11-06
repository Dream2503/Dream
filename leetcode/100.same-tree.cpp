/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        auto inOrder = [](TreeNode *root1, TreeNode *root2, bool &res, auto inOrder) -> void {
            if (res and root1 and root2) {
                inOrder(root1->left, root2->left, res, inOrder);
                if (root1->val != root2->val) res = false;
                inOrder(root1->right, root2->right, res, inOrder);
            }
            else if (root1 or root2) res = false;
        };
        inOrder(p, q, res, inOrder);
        return res;
    }
};
// @lc code=end

