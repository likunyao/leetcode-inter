/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
#include <vector>
using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            tree.resize(0);
        }
        else
        {
            tree.resize(2 * nums.size());
            build(0, nums.size() - 1, 1, tree, nums);
        }
    }

    void update(int i, int val)
    {
        upd(i, val, 1, 0, (tree.size() / 2) - 1);
    }

    int sumRange(int i, int j)
    {
        if (tree.size() == 0)
        {
            return 0;
        }

        int res = search(1, i, j, 0, (tree.size() / 2) - 1);
        return res;
    }

private:
    vector<int> tree;
    void build(int s, int t, int p, vector<int> &d, vector<int> &nums)
    {
        if (s == t)
        {
            d[p] = nums[s];
            return;
        }
        int m = (s + t) / 2;
        build(s, m, 2 * p, d, nums);
        build(m + 1, t, 2 * p + 1, d, nums);
        d[p] = d[2 * p] + d[2 * p + 1];
        return;
    }
    int search(int root, int i, int j, int s, int t)
    {
        int r = 0;
        if (i == s && j == t)
        {
            r += tree[root];
            return r;
        }
        int m = (s + t) / 2;
        if (j <= m)
        {
            r += search(2 * root, i, j, s, m);
        }
        else if (i > m)
        {
            r += search(2 * root + 1, i, j, m + 1, t);
        }
        else
        {
            r = r + search(2 * root, i, m, s, m) + search(2 * root + 1, m + 1, j, m + 1, t);
        }
        return r;
    }
    void upd(int i, int val, int p, int s, int t)
    {
        if (s == t && s == i)
        {
            tree[p] = val;
            return;
        }
        int m = (s + t) / 2;
        if (i <= m)
        {
            upd(i, val, 2 * p, s, m);
        }
        else
        {
            upd(i, val, 2 * p + 1, m + 1, t);
        }
        tree[p] = tree[2 * p] + tree[2 * p + 1];
        return;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
