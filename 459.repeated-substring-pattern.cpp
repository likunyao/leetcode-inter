/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>
using std::string;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string str = s + s;
        str = str.substr(1, str.size() - 2);
        if (str.find(s) == -1)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
