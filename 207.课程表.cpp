/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        map<int, set<int>> mmp;
        vector<int> indegree(numCourses, 0);
        for (auto &&v : prerequisites)
        {
            mmp[v[0]].insert(v[1]);
            indegree[v[1]]++;
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
        while (!que.empty())
        {
            int r = que.front();
            que.pop();
            cnt++;
            for (auto &&n : mmp[r])
            {
                indegree[n]--;
                if (indegree[n] == 0)
                {
                    que.push(n);
                }
            }
        }
        return cnt == numCourses;
    }
};
// @lc code=end
