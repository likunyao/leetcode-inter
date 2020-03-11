/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return res;
    }
    int depth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ld = depth(root->left);
        int rd = depth(root->right);
        res = max(res, ld + rd);
        return max(ld, rd) + 1;
    }
};
// @lc code=end
