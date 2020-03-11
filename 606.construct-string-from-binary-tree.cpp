/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode *t)
    {
        string res = dfs(t);
        return res;
    }
    string dfs(TreeNode *t)
    {
        if (t == NULL)
        {
            return "";
        }
        string tmp = to_string(t->val);

        if (t->left == NULL && t->right == NULL)
        {
            tmp = tmp;
        }
        else if (t->right == NULL)
        {
            tmp = tmp + "(" + dfs(t->left) + ")" + dfs(t->right);
        }
        else
        {
            tmp = tmp + "(" + dfs(t->left) + ")(" + dfs(t->right) + ")";
        }

        return tmp;
    }
};
// @lc code=end
