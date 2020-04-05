/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
        {
            return len;
        }
        vector<int> dp(len, 1);
        for (size_t i = 1; i < len; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
