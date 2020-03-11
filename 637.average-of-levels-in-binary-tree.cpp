/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            double sum = 0.0, n = count;
            while (count > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                count--;
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            res.push_back(sum / n);
        }
        return res;
    }
};
// @lc code=end
