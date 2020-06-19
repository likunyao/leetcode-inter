/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int gas_total = 0, cost_total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            gas_total += gas[i];
            cost_total += cost[i];
        }
        if (gas_total < cost_total)
        {
            return -1;
        }
        int sum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sum += (gas[i] - cost[i]);
            if (sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
// @lc code=end
