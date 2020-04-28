/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> res;
        int start = 0, end = 0;
        for (size_t i = 1; i < S.length(); i++)
        {
            if (S[i] == S[i - 1])
            {
                end = i;
                if (i == S.length() - 1 && end - start >= 2)
                {
                    res.push_back({start, end});
                }
            }
            else
            {
                if (end - start >= 2)
                {
                    res.push_back({start, end});
                }
                start = i;
                end = i;
            }
        }
        return res;
    }
};
// @lc code=end
