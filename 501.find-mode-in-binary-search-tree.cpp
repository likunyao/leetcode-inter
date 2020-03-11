/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> vec;
    vector<int> res;
    vector<int> findMode(TreeNode *root)
    {
        int max = 0;
        int cur = 0;
        LDR(root);
        if (vec.size() == 1)
        {
            res.push_back(vec[0]);
        }

        for (size_t i = 1; i < vec.size(); i++)
        {
            if (vec[i] == vec[i - 1])
            {
                cur++;
            }
            else
            {
                cur = 0;
            }
            if (cur == max)
            {
                if (i == 1 && cur == 0)
                {
                    res.push_back(vec[0]);
                }
                res.push_back(vec[i]);
            }
            else if (cur > max)
            {
                res.clear();
                max = cur;
                res.push_back(vec[i]);
            }
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
