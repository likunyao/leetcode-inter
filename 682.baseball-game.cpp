/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> point;
        for (auto &&s : ops)
        {
            if (s == "+")
            {
                int cur = point.top();
                point.pop();
                int pre = point.top();
                point.push(cur);
                point.push(cur + pre);
            }
            else if (s == "D")
            {
                point.push(2 * point.top());
            }
            else if (s == "C")
            {
                point.pop();
            }
            else
            {
                point.push(stoi(s));
            }
        }
        int res = 0;
        while (!point.empty())
        {
            res += point.top();
            point.pop();
        }
        return res;
    }
};
// @lc code=end
