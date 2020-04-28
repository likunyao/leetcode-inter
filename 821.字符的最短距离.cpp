/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> index;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == C)
            {
                index.push_back(i);
            }
        }
        vector<int> res;
        int n = INT32_MAX;
        for (int i = 0; i < S.length(); i++)
        {
            for (auto &&d : index)
            {
                n = min(n, abs(i - d));
            }
            res.push_back(n);
            n = INT32_MAX;
        }
        return res;
    }
};
// @lc code=end
