/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int res = 0;
        for (auto &&c : S)
        {
            if (J.find(c) != J.npos)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
