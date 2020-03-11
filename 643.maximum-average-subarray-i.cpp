/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0;
        for (size_t i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        double tmp = sum;
        for (size_t j = 0, i = k; i < nums.size();)
        {
            tmp += nums[i++];
            tmp -= nums[j++];
            sum = max(sum, tmp);
        }
        return sum / k;
    }
};
// @lc code=end
