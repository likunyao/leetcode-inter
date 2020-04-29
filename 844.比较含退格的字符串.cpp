/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string s, t;
        for (size_t i = 0; i < S.length(); i++)
        {
            if (S[i] != '#')
            {
                s += S[i];
            }
            else
            {
                if (s.length() != 0)
                {
                    s.erase(s.length() - 1, 1);
                }
            }
        }
        for (size_t i = 0; i < T.length(); i++)
        {
            if (T[i] != '#')
            {
                t += T[i];
            }
            else
            {
                if (t.length() != 0)
                {
                    t.erase(t.length() - 1, 1);
                }
            }
        }
        return s == t;
    }
};
// @lc code=end
