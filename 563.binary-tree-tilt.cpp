/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int res = 0;
    int findTilt(TreeNode *root)
    {
        dfs(root);
        return res;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        res += abs(l - r);
        return l + r + root->val;
    }
};
// @lc code=end
