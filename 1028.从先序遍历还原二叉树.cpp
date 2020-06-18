/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
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
// #include <string>
// using namespace std;
class Solution
{
public:
    int cur = 0, curD = 0;
    TreeNode *recoverFromPreorder(string S)
    {
        return dfs(0, S);
    }
    TreeNode *dfs(int depth, const string &S)
    {
        int val = 0;
        while (cur < S.length() && S[cur] != '-')
        {
            val = val * 10 + S[cur] - '0';
            cur++;
        }
        curD = 0;
        while (cur < S.length() && S[cur] == '-')
        {
            curD++;
            cur++;
        }
        TreeNode *res = new TreeNode(val);
        if (curD > depth)
        {
            res->left = dfs(curD, S);
        }
        if (curD > depth)
        {
            res->right = dfs(curD, S);
        }
        return res;
    }
};
// @lc code=end
