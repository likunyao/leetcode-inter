/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
#include <iostream>
using namespace std;

class Solution
{
public:
    int n = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
        {
            convertBST(root->right);
            root->val += n;
            n = root->val;
            convertBST(root->left);
        }
        return root;
    }
};
// @lc code=end
