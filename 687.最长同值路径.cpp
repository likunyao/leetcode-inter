/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int longestUnivaluePath(TreeNode *root)
    {
        int val = 0;
        dfs(root, val);
        return val;
    }
    int dfs(TreeNode *root, int &val)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left, val);
        int right = dfs(root->right, val);
        left = (root->left != nullptr && root->val == root->left->val) ? left + 1 : 0;
        right = (root->right != nullptr && root->val == root->right->val) ? right + 1 : 0;
        val = val >= (left + right) ? val : (left + right);
        return left >= right ? left : right;
    }
};
// @lc code=end
