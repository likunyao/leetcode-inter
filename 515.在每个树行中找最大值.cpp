/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
// #include <queue>
// #include <algorithm>
// using namespace std;
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            int maxValue = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                TreeNode *t = que.front();
                maxValue = max(maxValue, t->val);
                que.pop();
                if (t->left)
                {
                    que.push(t->left);
                }
                if (t->right)
                {
                    que.push(t->right);
                }
            }
            res.push_back(maxValue);
        }
        return res;
    }
};
// @lc code=end
