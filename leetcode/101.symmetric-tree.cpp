/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        auto inOrder = [](TreeNode *root1, TreeNode *root2, bool &res, auto inOrder) -> void {
            if (res and root1 and root2) {
                inOrder(root1->left, root2->right, res, inOrder);
                if (root1->val != root2->val) res = false;
                inOrder(root1->right, root2->left, res, inOrder);
            }
            else if (root1 or root2) res = false;
        };
        inOrder(root->left, root->right, res, inOrder);
        return res;
    }
};
// @lc code=end

