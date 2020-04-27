/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A == B)
        {
            return true;
        }
        for (size_t i = 0; i < A.length() - 1; i++)
        {
            help(A);
            if (A == B)
            {
                return true;
            }
        }
        return false;
    }
    void help(string &s)
    {
        char c = s.front();
        s.erase(0, 1);
        s += c;
    }
};
// @lc code=end
