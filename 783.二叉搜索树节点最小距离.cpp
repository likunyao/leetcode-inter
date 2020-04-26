/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    vector<int> v;
    int minDiffInBST(TreeNode *root)
    {
        dfs(root);
        int res = INT32_MAX;
        for (size_t i = 1; i < v.size(); i++)
        {
            res = min(v[i] - v[i - 1], res);
        }
        return res;
    }
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
};
// @lc code=end
