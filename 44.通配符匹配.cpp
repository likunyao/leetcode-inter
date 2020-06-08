/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < p.length(); j++)
        {
            if (p[j] == '*')
            {
                dp[0][j + 1] = dp[0][j];
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < p.length(); j++)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if (p[j] == '*')
                {
                    dp[i + 1][j + 1] = dp[i][j] || dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
// @lc code=end
