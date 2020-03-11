/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        return dfs(root, root->val);
    }
    int dfs(TreeNode *root, int min)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->val > min)
        {
            return root->val;
        }
        int l = dfs(root->left, min);
        int r = dfs(root->right, min);
        if (l > min && r > min)
        {
            return l > r ? r : l;
        }
        return max(l, r);
    }
};
// @lc code=end
