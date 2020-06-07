/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> que;
        unordered_map<int, int> mmp;
        for (auto &&n : nums)
        {
            mmp[n]++;
        }
        unordered_map<int, int> pmm;
        for (auto &&i : mmp)
        {
            pmm[i.second] = i.first;
        }
        
        for (auto &&i : mmp)
        {
            if (que.size() < k)
            {
                que.push(i.second);
            }
            else
            {
                if (i.second > que.top())
                {
                    que.pop();
                    que.push(i.second);
                }
            }
        }
        vector<int> res;
        while (!que.empty())
        {
            res.push_back(pmm[que.top()]);
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
