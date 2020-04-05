/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return true;
        }
        int count = 0;
        for (size_t i = 1; i < nums.size() && count < 2; i++)
        {
            if (nums[i - 1] <= nums[i])
            {
                continue;
            }
            count++;
            if (i >= 2 && nums[i - 2] > nums[i])
            {
                nums[i] = nums[i - 1];
            }
            else
            {
                nums[i - 1] = nums[i];
            }
        }
        return count <= 1;
    }
};
// @lc code=end
