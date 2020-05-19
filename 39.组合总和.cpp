/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, candidates, tmp, 0, 0, target);
        return res;
    }
    void dfs(vector<vector<int>> &res, const vector<int> &candiates, vector<int> tmp, int index, int sum, int target)
    {
        if (sum == target)
        {
            res.push_back(tmp);
        }
        else if (sum > target)
        {
            return;
        }
        for (size_t i = index; i < candiates.size(); i++)
        {
            tmp.push_back(candiates[i]);
            dfs(res, candiates, tmp, i, sum + candiates[i], target);
            tmp.pop_back();
        }
        return;
    }
};
// @lc code=end
