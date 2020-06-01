/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inOrderRoot = index[preorder[preStart]];
        root->left = dfs(preorder, inorder, preStart + 1, preStart + inOrderRoot - inStart, inStart, inOrderRoot - 1);
        root->right = dfs(preorder, inorder, preStart + inOrderRoot - inStart + 1, preEnd, inOrderRoot + 1, inEnd);
        return root;
    }
};
// @lc code=end
