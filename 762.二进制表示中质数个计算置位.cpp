/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
#include <math.h>
class Solution
{
public:
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        for (size_t i = L; i <= R; i++)
        {
            if (Primer(count1(i)))
            {
                res++;
            }
        }
        return res;
    }
    int count1(int n)
    {
        int res = 0;
        while (n)
        {
            n &= (n - 1);
            res++;
        }
        return res;
    }
    bool Primer(int n)
    {
        if (n <= 3)
            return n > 1;
        if (n % 2 == 0)
            return false;
        int sq = sqrt(n);
        for (int i = 3; i <= sq; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
