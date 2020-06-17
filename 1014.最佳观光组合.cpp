/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &A)
    {
        int res = INT_MIN;
        int tmp = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            res = max(res, tmp + A[i] - i);
            tmp = max(tmp, A[i] + i);
        }

        return res;
    }
};
// @lc code=end
