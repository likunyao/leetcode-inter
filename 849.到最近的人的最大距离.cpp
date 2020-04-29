/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        vector<int> dp(seats.size(), 0);
        dp[0] = seats[0] == 0 ? 1 : 0;
        for (size_t i = 1; i < seats.size(); i++)
        {
            if (seats[i] == 0)
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int count1 = 0;
        for (size_t i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 0)
            {
                count1++;
            }
            else
            {
                break;
            }
        }
        int count2 = 0;
        for (int i = seats.size() - 1; i >= 0; i--)
        {
            if (seats[i] == 0)
            {
                count2++;
            }
            else
            {
                break;
            }
        }

        int res = -1;
        for (auto &&n : dp)
        {
            res = max(n, res);
        }
        if (dp[dp.size() - 1] == res || dp[res - 1] == res)
        {
            return max(res, max(count1, count2));
        }
        return max(res / 2 + res % 2, max(count1, count2));
    }
};
// @lc code=end
