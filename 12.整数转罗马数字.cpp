/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        while (num / 1000)
        {
            res += string(num / 1000, 'M');
            num %= 1000;
        }
        while (num / 100)
        {
            int val = num / 100;
            if (val < 4)
            {
                res += string(val, 'C');
            }
            else if (val == 4)
            {
                res += "CD";
            }
            else if (val < 9)
            {
                res += "D";
                res += string(val - 5, 'C');
            }
            else
            {
                res += "CM";
            }
            num %= 100;
        }
        while (num / 10)
        {
            int val = num / 10;
            if (val < 4)
            {
                res += string(val, 'X');
            }
            else if (val == 4)
            {
                res += "XL";
            }
            else if (val < 9)
            {
                res += "L";
                res += string(val - 5, 'X');
            }
            else
            {
                res += "XC";
            }
            num %= 10;
        }
        if (num < 4)
        {
            res += string(num, 'I');
        }
        else if (num == 4)
        {
            res += "IV";
        }
        else if (num < 9)
        {
            res += "V";
            res += string(num - 5, 'I');
        }
        else
        {
            res += "IX";
        }
        return res;
    }
};
// @lc code=end
