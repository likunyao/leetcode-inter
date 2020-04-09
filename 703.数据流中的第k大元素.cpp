/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class KthLargest
{
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto &&i : nums)
        {
            add(i);
        }
    }

    int add(int val)
    {
        if (smallHeap.size() < k)
        {
            smallHeap.push(val);
        }
        else if (val > smallHeap.top())
        {
            smallHeap.pop();
            smallHeap.push(val);
        }
        return smallHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
