/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int size_1 = points.size();
        vector<float> nums;
        float max = 0;
        for (int i = 0; i < size_1 - 2; i++)
        {
            float x1 = points[i][0];
            float y1 = points[i][1];
            for (int j = i + 1; j < size_1 - 1; j++)
            {
                float x2 = points[j][0];
                float y2 = points[j][1];
                for (int k = j + 1; k < size_1; k++)
                {
                    float x3 = points[k][0];
                    float y3 = points[k][1];
                    float sum = 0.5 * abs((x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2));
                    if (sum > max)
                        max = sum;
                }
            }
        }
        return max;
    }
};
// @lc code=end
