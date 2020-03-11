/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        auto it = s.begin();
        while (it + k <= s.end())
        {
            reverse(it, it + k);
            it += 2 * k;
        }
        if (it + k > s.end())
        {
            reverse(it, s.end());
        }
        return s;
    }
};
// @lc code=end
