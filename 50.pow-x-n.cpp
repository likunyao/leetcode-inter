/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 1.0)
            return x;
        if (n < -1)
            return 1 / (myPow(x, -(n + 1)) * x);
        if (n == -1)
            return 1 / x;
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double ret = myPow(x, n / 2);
        if (n % 2 == 0)
            return ret * ret;
        else
            return ret * ret * x;
    }
};
// @lc code=end
