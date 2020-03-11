/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int one = x ^ y;
        int res;
        for (res = 0; one; res++)
        {
            one &= (one - 1);
        }
        return res;
    }
};
// @lc code=end
