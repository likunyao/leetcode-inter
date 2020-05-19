/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(res, candidates, tmp, 0, 0, target);
        set<vector<int>> ss(res.begin(), res.end());
        res.assign(ss.begin(), ss.end());
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
            dfs(res, candiates, tmp, i + 1, sum + candiates[i], target);
            tmp.pop_back();
        }
        return;
    }
};
// @lc code=end
