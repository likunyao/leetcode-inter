/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int rotatedDigits(int N)
    {
        int res = 0;
        for (size_t i = 1; i <= N; i++)
        {
            if (isGood(i))
            {
                res++;
            }
        }
        return res;
    }
    bool isGood(int n)
    {
        int d;
        int c = 0;
        while (n)
        {
            d = n % 10;
            if (d == 3 || d == 4 || d == 7)
            {
                return false;
            }
            else if (d == 2 || d == 5 || d == 6 || d == 9)
            {
                c++;
            }
            n /= 10;
        }
        return c > 0;
    }
};
// @lc code=end
