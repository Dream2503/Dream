/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> hash;
        vector<int> res;
        int max = -10e5;
        auto inOrder = [&hash](TreeNode *root, auto inOrder) -> void {
            if (root) {
                inOrder(root->left, inOrder);
                hash[root->val]++;
                inOrder(root->right, inOrder);
            }
        };
        inOrder(root, inOrder);
        for (auto element: hash) if (element.second > max) max = element.second;
        for (auto element: hash) if (element.second == max) res.push_back(element.first);
        return res;
    }
};
// @lc code=end

