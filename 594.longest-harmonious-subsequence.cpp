/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> mmp;
        for (auto &&i : nums)
        {
            mmp[i]++;
        }
        auto p = mmp.begin(), q = p;
        int res = 0;
        for (; p != mmp.end(); p++)
        {
            if (p->first - q->first == 1)
            {
                res = max(res, p->second + q->second);
            }
            q = p;
        }
        return res;
    }
};
// @lc code=end
