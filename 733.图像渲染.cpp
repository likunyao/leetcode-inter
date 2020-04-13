/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
        {
            return image;
        }
        int color = image[sr][sc];
        dfs(image, sr, sc, newColor, color);
        return image;
    }
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int color)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] == newColor || image[sr][sc] != color)
        {
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, newColor, color);
        dfs(image, sr + 1, sc, newColor, color);
        dfs(image, sr, sc - 1, newColor, color);
        dfs(image, sr, sc + 1, newColor, color);
    }
};
// @lc code=end
