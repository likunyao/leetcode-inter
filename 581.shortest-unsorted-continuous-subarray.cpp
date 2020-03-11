/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int i = 0;
        for (; i < tmp.size(); i++)
        {
            if (nums[i] != tmp[i])
            {
                break;
            }
        }
        if (i == nums.size())
        {
            return 0;
        }
        int j = nums.size() - 1;
        for (; j >= 0; j--)
        {
            if (nums[j] != tmp[j])
            {
                break;
            }
        }
        return j - i + 1;
    }
};
// @lc code=end
