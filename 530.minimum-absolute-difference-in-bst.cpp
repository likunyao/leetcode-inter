/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> vec;
    int getMinimumDifference(TreeNode *root)
    {
        LDR(root);
        int res = INT_MAX;
        int tmp = INT_MAX;
        for (size_t i = 1; i < vec.size(); i++)
        {
            tmp = abs(vec[i] - vec[i - 1]);
            res = res < tmp ? res : tmp;
        }
        return res;
    }

    void LDR(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        LDR(root->left);
        vec.push_back(root->val);
        LDR(root->right);
    }
};
// @lc code=end
