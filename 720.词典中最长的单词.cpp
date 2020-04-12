/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    struct TireNode
    {
        bool flag;
        vector<TireNode *> children;
        TireNode() : flag(false), children(26, nullptr) {}
    };

    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        auto root = new TireNode();
        TireNode *head = root;
        root->flag = true;
        string res;
        for (auto &&s : words)
        {
            root = head;
            for (auto &&c : s)
            {
                if (root->children[c - 'a'] == nullptr)
                {
                    root->children[c - 'a'] = new TireNode();
                }
                root = root->children[c - 'a'];
            }
            root->flag = true;
        }
        for (auto &&s : words)
        {
            if (search(head, s))
            {
                if (s.length() > res.length())
                {
                    res = s;
                }
                else if (s.length() == res.length() && s < res)
                {
                    res = s;
                }
            }
        }
        return res;
    }
    bool search(TireNode *head, const string &s)
    {
        for (auto &&c : s)
        {
            if (head->flag == false)
            {
                return false;
            }
            head = head->children[c - 'a'];
        }
        return true;
    }
};
// @lc code=end
