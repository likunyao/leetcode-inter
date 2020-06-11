/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> res(T.size(), 0);
        stack<int> sta;
        for (int i = 0; i < T.size(); i++)
        {
            while (!sta.empty() && T[i] > T[sta.top()])
            {
                res[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }
        return res;
    }
};
// @lc code=end
