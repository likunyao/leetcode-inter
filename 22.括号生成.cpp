/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        dfs(res, 0, 0, "", n);
        return res;
    }
    void dfs(vector<string> &res, int l, int r, string temp, int n)
    {
        if (l > n || r > n || r > l)
        {
            return;
        }
        if (l == n && r == n)
        {
            res.push_back(temp);
            return;
        }
        dfs(res, l + 1, r, temp + '(', n);
        dfs(res, l, r + 1, temp + ')', n);
        return;
    }
};
// @lc code=end
