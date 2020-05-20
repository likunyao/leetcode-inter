/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int res = 0;
        vector<vector<int>> tmp(n, vector<int>(n, 0));
        dfs(0, n, res, tmp);
        return res;
    }
    void dfs(int row, int n, int &res, vector<vector<int>> tmp)
    {
        if (row == n)
        {
            res++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (match(tmp, row, i, n))
            {
                tmp[row][i] = 1;
                dfs(row + 1, n, res, tmp);
                tmp[row][i] = 0;
            }
        }
        return;
    }
    bool match(vector<vector<int>> &tmp, int row, int col, int n)
    {
        for (int i = 0; i <= row; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp[i][j] == 1)
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
