/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, n, k, 1);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> tmp, const int n, const int k, int step)
    {
        if (tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = step; i <= n; i++)
        {
            tmp.push_back(i);
            dfs(res, tmp, n, k, i + 1);
            tmp.pop_back();
        }
        return;
    }
};
// @lc code=end
