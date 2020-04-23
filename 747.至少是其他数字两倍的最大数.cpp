/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int index = -1;
        int max = INT32_MIN;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i != index && max - nums[i] < nums[i])
            {
                return -1;
            }
        }
        return index;
    }
};
// @lc code=end
