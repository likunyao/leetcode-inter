/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int degree = 0;
        int res = INT32_MAX;
        unordered_map<int, int> cnt;
        unordered_map<int, pair<int, int>> pos;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (++cnt[nums[i]] == 1)
            {
                pos[nums[i]] = {i, i};
            }
            else
            {
                pos[nums[i]].second = i;
            }
            degree = max(degree, cnt[nums[i]]);
        }
        for (auto &&i : cnt)
        {
            if (degree == i.second)
            {
                res = min(res, pos[i.first].second - pos[i.first].first + 1);
            }
        }
        return res;
    }
};
// @lc code=end
