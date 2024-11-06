/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        auto inOrder = [](TreeNode *root, vector<int> &res, auto inOrder) -> void {
            if (root) {
                inOrder(root->left, res, inOrder);
                res.push_back(root->val);
                inOrder(root->right, res, inOrder);
            }
        };
        inOrder(root, res, inOrder);
        return res;
    }
};
// @lc code=end

