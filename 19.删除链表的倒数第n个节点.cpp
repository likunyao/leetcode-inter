/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *le = head, *ri = head;
        for (int i = 0; i < n; i++)
        {
            ri = ri->next;
        }
        if (ri == nullptr)
        {
            return head->next;
        }

        while (ri->next)
        {
            le = le->next;
            ri = ri->next;
        }
        le->next = le->next->next;
        return head;
    }
};
// @lc code=end
