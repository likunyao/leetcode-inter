/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string toLowerCase(string str)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
        }
        return str;
    }
};
// @lc code=end
