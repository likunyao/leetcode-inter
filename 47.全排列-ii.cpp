/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> used(nums.size(), 0);
        dfs(res, nums, tmp, used);
        set<vector<int>> ss(res.begin(), res.end());
        res.assign(ss.begin(), ss.end());
        return res;
    }
    void dfs(vector<vector<int>> &res, const vector<int> &nums, vector<int> tmp, vector<int> &used)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            tmp.push_back(nums[i]);
            used[i] = 1;
            dfs(res, nums, tmp, used);
            tmp.pop_back();
            used[i] = 0;
        }
        return;
    }
};
// @lc code=end
