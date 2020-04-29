/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> res(A[0].size(), vector<int>(A.size(), 0));
        for (size_t i = 0; i < A.size(); i++)
        {
            for (size_t j = 0; j < A[0].size(); j++)
            {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
