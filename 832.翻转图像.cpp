/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (auto &&v : A)
        {
            reverse(v.begin(), v.end());
        }
        for (auto &&v : A)
        {
            for (auto &&n : v)
            {
                n ^= 1;
            }
        }
        return A;
    }
};
// @lc code=end
