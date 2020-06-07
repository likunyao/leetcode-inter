/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
// #include <vector>
// using namespace std;
class Solution
{
    ListNode *Merge(ListNode *a, ListNode *b)
    {
        if (a == nullptr)
        {
            return b;
        }
        if (b == nullptr)
        {
            return a;
        }
        ListNode *res = nullptr;
        if (a->val <= b->val)
        {
            res = a;
            res->next = Merge(a->next, b);
        }
        else
        {
            res = b;
            res->next = Merge(a, b->next);
        }
        return res;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        ListNode *res = nullptr;
        for (auto &&i : lists)
        {
            res = Merge(res, i);
        }
        return res;
    }
};
// @lc code=end
