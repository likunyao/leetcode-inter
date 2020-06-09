/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = max(dp[i], (i - j) * dp[j]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
