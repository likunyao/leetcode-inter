/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
// #include <vector>
// #include <unordered_map>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
    unordered_map<int, int> index;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int m = index[postorder[postEnd]];
        root->left = dfs(inorder, postorder, inStart, m - 1, postStart, postStart + m - inStart - 1);
        root->right = dfs(inorder, postorder, m + 1, inEnd, postStart + m - inStart, postEnd - 1);
        return root;
    }
};
// @lc code=end
