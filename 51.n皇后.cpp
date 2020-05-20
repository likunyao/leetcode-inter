/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        dfs(0, n, res, tmp);
        return res;
    }
    void dfs(int row, int n, vector<vector<string>> &res, vector<string> tmp)
    {
        if (row == n)
        {
            res.push_back(tmp);
            return;
        }
        for (size_t i = 0; i < n; i++)
        {
            if (match(tmp, row, i, n))
            {
                tmp[row][i] = 'Q';
                dfs(row + 1, n, res, tmp);
                tmp[row][i] = '.';
            }
        }
        return;
    }
    bool match(vector<string> &tmp, int row, int col, int n)
    {
        for (int i = 0; i <= row; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp[i][j] == 'Q')
                {
                    if (abs(i - row) == abs(j - col) || j == col)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end
