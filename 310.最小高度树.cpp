/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
        {
            return {};
        }
        if (n == 1)
        {
            return {0};
        }
        if (n == 2)
        {
            return {0, 1};
        }
        vector<int> res;
        vector<unordered_set<int>> adjs(n);
        for (auto &&edge : edges)
        {
            adjs[edge[0]].insert(edge[1]);
            adjs[edge[1]].insert(edge[0]);
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (adjs[i].size() == 1)
            {
                que.push(i);
            }
        }
        int tmp = n;
        while (tmp > 2)
        {
            int a = que.size();
            tmp -= a;
            for (int i = 0; i < a; i++)
            {
                int node = que.front();
                que.pop();
                for (auto &&single : adjs[node])
                {
                    adjs[single].erase(node);
                    if (adjs[single].size() == 1)
                    {
                        que.push(single);
                    }
                }
            }
        }
        while (!que.empty())
        {
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};
// @lc code=end
