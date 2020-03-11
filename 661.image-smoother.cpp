/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                res[i][j] = pro(i, j, M);
            }
        }
        return res;
    }
    int pro(int a, int b, vector<vector<int>> &v)
    {
        int res = 0;
        int count = 0;
        int m = v.size();
        int n = v[0].size();
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if ((a + i) >= 0 && (a + i) < m && (b + j) >= 0 && (b + j) < n)
                {
                    res += v[a + i][b + j];
                    count++;
                }
            }
        }
        return res / count;
    }
};
// @lc code=end
