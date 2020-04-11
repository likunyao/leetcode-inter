/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
#include <vector>
#include <list>
using namespace std;

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    vector<list<int>> bucket;
    const int mod = 1024;
    MyHashSet()
    {
        bucket.resize(mod);
    }

    void add(int key)
    {
        int index = key % mod;
        for (auto &&i : bucket[index])
        {
            if (i == key)
            {
                return;
            }
        }
        bucket[index].push_back(key);
    }

    void remove(int key)
    {
        int index = key % mod;
        for (auto &&i : bucket[index])
        {
            if (i == key)
            {
                bucket[index].remove(key);
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int index = key % mod;
        for (auto &&i : bucket[index])
        {
            if (i == key)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
