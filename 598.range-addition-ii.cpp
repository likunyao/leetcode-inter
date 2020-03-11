/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int a = m;
        int b = n;
        for (auto &v : ops)
        {
            a = a > v[0] ? v[0] : a;
            b = b > v[1] ? v[1] : b;
        }
        return a * b;
    }
};
// @lc code=end
