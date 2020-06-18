/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res;
        for (int i = 0; i < s.length(); i++)
        {
            string s1 = foo(s, i, i);
            string s2 = foo(s, i, i + 1);
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
    string foo(const string &s, int l, int r)
    {
        string res;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
// @lc code=end
