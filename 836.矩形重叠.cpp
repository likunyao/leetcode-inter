/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        int w = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int h = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        if (w <= 0 || h <= 0)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
