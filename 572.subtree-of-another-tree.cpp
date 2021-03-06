/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
        {
            return true;
        }
        if (!s && t)
        {
            return false;
        }
        return isSametree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSametree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
        {
            return true;
        }
        return s && t && s->val == t->val && isSametree(s->left, t->left) && isSametree(s->right, t->right);
    }
};
// @lc code=end
