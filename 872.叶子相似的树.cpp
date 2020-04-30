/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
#include <vector>
using namespace std;

class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        return v1 == v2;
    }
    void dfs(TreeNode *root, vector<int> &leaf)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left, leaf);
        if (root->left == nullptr && root->right == nullptr)
        {
            leaf.push_back(root->val);
        }
        dfs(root->right, leaf);
    }
};
// @lc code=end
