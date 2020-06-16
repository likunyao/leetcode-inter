/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// #include <vector>
// #include <stack>
// using namespace std;
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        stack<TreeNode *> sta;
        sta.push(root);
        while (!sta.empty())
        {
            TreeNode *t = sta.top();
            sta.pop();
            if (t != nullptr)
            {
                sta.push(t);
                sta.push(nullptr);
                if (t->right)
                {
                    sta.push(t->right);
                }
                if (t->left)
                {
                    sta.push(t->left);
                }
            }
            else
            {
                res.push_back(sta.top()->val);
                sta.pop();
            }
        }
        return res;
    }
};
// @lc code=end
