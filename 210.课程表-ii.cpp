/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &&v : prerequisites)
        {
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }
        int cnt = 0;
        vector<int> res;
        while (!que.empty())
        {
            int t = que.front();
            que.pop();
            cnt++;
            res.push_back(t);
            for (auto &&n : graph[t])
            {
                indegree[n]--;
                if (indegree[n] == 0)
                {
                    que.push(n);
                }
            }
        }
        if (cnt != numCourses)
        {
            res.clear();
        }
        return res;
    }
};
// @lc code=end
