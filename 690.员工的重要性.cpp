/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        queue<Employee *> q;
        Employee *boss;
        int sum = 0;
        boss = find_boss(employees, id);
        q.push(boss);
        while (!q.empty())
        {
            int n = q.size();
            for (size_t i = 0; i < n; i++)
            {
                Employee *e = q.front();
                q.pop();
                sum += e->importance;
                for (auto &&i : e->subordinates)
                {
                    q.push(find_boss(employees, i));
                }
            }
        }
        return sum;
    }
    Employee *find_boss(vector<Employee *> employees, int id)
    {
        Employee *boss;
        for (auto &&e : employees)
        {
            if (e->id == id)
            {
                boss = e;
                break;
            }
        }
        return boss;
    }
};
// @lc code=end
