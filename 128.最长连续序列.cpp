/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int res = 1;
        int tmp = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                tmp++;
                res = max(tmp, res);
            }
            else if (nums[i] == nums[i - 1])
            {
                continue;
            }

            else
            {
                tmp = 1;
            }
        }
        return res;
    }
};
// @lc code=end
