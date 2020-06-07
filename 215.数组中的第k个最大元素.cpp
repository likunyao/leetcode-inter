/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> que;
        for (auto &&n : nums)
        {
            if (que.size() < k)
            {
                que.push(n);
            }
            else
            {
                if (n > que.top())
                {
                    que.pop();
                    que.push(n);
                }
            }
        }
        return que.top();
    }
};
// @lc code=end
