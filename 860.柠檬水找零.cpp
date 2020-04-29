/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (auto &&n : bills)
        {
            if (n == 5)
            {
                five++;
            }
            if (n == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            if (n == 20)
            {
                if (five <= 0)
                {
                    return false;
                }
                if (ten <= 0)
                {
                    if (five < 3)
                    {
                        return false;
                    }
                    else
                    {
                        five -= 3;
                    }
                }
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
            }
        }
        return true;
    }
};
// @lc code=end
