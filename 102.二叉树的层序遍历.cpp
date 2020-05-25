/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root == nullptr)
        {
            return res;
        }
        q.push(root);
        int n;
        vector<int> level;
        while (!q.empty())
        {
            n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};
// @lc code=end
