/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num <= 0)
        {
            return false;
        }
        int sum = 0;
        for (size_t i = 1; i * i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i * i != num)
                {
                    sum += num / i;
                }
            }
        }
        return sum == 2 * num;
    }
};
// @lc code=end
