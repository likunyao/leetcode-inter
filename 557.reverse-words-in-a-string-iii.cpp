/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s == "")
        {
            return s;
        }

        string res = "";
        string tmp = "";
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' || i == s.length() - 1)
            {
                if (i == s.length() - 1)
                {
                    tmp += s[i];
                }

                reverse(tmp.begin(), tmp.end());
                res += tmp + " ";
                tmp.clear();
            }
            else
            {
                tmp += s[i];
            }
        }
        res.erase(res.length() - 1, 1);
        return res;
    }
};
// @lc code=end
