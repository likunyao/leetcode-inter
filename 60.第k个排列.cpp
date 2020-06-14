/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string res;
        string s = string("123456789").substr(0, n);
        for (int i = 1; i < k; i++)
        {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};
// @lc code=end
