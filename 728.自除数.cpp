/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (size_t i = left; i <= right; i++)
        {
            if (fun(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
    bool fun(int n)
    {
        int t = n;
        int e;
        while (t)
        {
            e = t % 10;
            if (e == 0 || n % e != 0)
            {
                return false;
            }
            t /= 10;
        }
        return true;
    }
};
// @lc code=end
