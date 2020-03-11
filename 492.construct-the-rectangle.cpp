/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int W = sqrt(area);
        while (area % W)
        {
            W--;
        }
        return {area / W, W};
    }
};
// @lc code=end
