/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size(), mid = size / 2, i;
        TreeNode *res = new TreeNode(nums[mid]), *current = res;

        for (i = mid - 1; i > -1; i--) {
            current->left = new TreeNode(nums[i]);
            current = current->left;
        }
        for (i = mid + 1; i < size; i++) {
            current->right = new TreeNode(nums[i]);
            current = current->right;
        }
        return res;
    }
};
// @lc code=end

