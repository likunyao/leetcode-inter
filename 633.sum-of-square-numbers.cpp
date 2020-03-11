/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
#include <algorithm>
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c <= 2)
        {
            return true;
        }
        long i = 0;
        long j = static_cast<long>(sqrt(c));
        while (i <= j)
        {
            long total = i * i + j * j;
            if (total < c)
            {
                i++;
            }
            else if (total > c)
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
