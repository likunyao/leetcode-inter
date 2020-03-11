/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        string res = "";
        if (num == 0)
        {
            res += "0";
            return res;
        }
        int flag = 1;
        if (num < 0)
        {
            flag = 0;
            num = -num;
        }
        while (num)
        {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        if (!flag)
        {
            res = "-" + res;
        }
        return res;
    }
};
// @lc code=end
