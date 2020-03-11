/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> res(2, 0);
        vector<int> mmp(nums.size() + 1, 0);
        for (auto &&n : nums)
        {
            mmp[n]++;
        }
        for (size_t i = 1; i < mmp.size(); i++)
        {
            if (mmp[i] == 2)
            {
                res[0] = i;
            }
            if (mmp[i] == 0)
            {
                res[1] = i;
            }
        }
        return res;
    }
};
// @lc code=end
