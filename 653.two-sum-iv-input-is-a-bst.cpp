/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode *root, int k)
    {
        dfs(root);
        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            if (v[i] + v[j] < k)
            {
                i++;
            }
            else if (v[i] + v[j] > k)
            {
                j--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
    void dfs(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
};
// @lc code=end
