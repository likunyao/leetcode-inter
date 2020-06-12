/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 先序遍历构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #include <vector>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return dfs(0, preorder.size() - 1, preorder);
    }
    TreeNode *dfs(int start, int end, const vector<int> &preorder)
    {
        if (start == end)
        {
            return new TreeNode(preorder[start]);
        }

        TreeNode *root = new TreeNode(preorder[start]);
        int r = help(start, end, preorder);
        if (r != start + 1)
        {
            root->left = dfs(start + 1, r - 1, preorder);
        }
        if (r <= end)
        {
            root->right = dfs(help(start, end, preorder), end, preorder);
        }

        return root;
    }
    int help(int start, int end, const vector<int> &preorder)
    {
        int base = preorder[start];
        int res;
        for (int i = start; i <= end; i++)
        {
            if (preorder[i] > base)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
