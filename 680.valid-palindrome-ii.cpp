/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return is(s, i + 1, j) || is(s, i, j - 1);
            }
        }
        return true;
    }
    bool is(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
// @lc code=end
