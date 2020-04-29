/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        int l = 0, r = A.size() - 1, m;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (A[m - 1] <= A[m] && A[m] <= A[m + 1])
            {
                l = m + 1;
            }
            else if (A[m - 1] >= A[m] && A[m] >= A[m + 1])
            {
                r = m - 1;
            }
            else
            {
                break;
            }
        }
        return m;
    }
};
// @lc code=end
