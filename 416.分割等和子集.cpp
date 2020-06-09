/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &&n : nums)
        {
            sum += n;
        }
        if (sum % 2)
        {
            return false;
        }
        int W = sum / 2;
        sort(nums.rbegin(), nums.rend());
        return dfs(0, nums.size(), 0, sum, W, nums);
    }
    bool dfs(int i, int n, int tmpsum, int processed, int W, vector<int> &nums)
    {
        if (tmpsum == W)
        {
            return true;
        }

        if (i >= n)
        {
            if (tmpsum == W)
            {
                return true;
            }
            return false;
        }
        else
        {
            if (tmpsum + nums[i] <= W)
            {
                if (dfs(i + 1, n, tmpsum + nums[i], processed - nums[i], W, nums))
                {
                    return true;
                }
            }
            if (tmpsum + processed >= W)
            {
                if (dfs(i + 1, n, tmpsum, processed - nums[i], W, nums))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
