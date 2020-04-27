/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int row = 1, col = 0;
        for (auto &&c : S)
        {
            if ((100 - col) >= widths[c - 'a'])
            {
                col += widths[c - 'a'];
            }
            else
            {
                row++;
                col = widths[c - 'a'];
            }
        }
        return {row, col};
    }
};
// @lc code=end
