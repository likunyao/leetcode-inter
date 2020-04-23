/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短完整词
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        string res = "aaaaaaaaaaaaaaaa";
        map<char, int> m;
        for (auto &&c : licensePlate)
        {
            if (isalpha(c))
            {
                m[tolower(c)]++;
            }
        }
        map<char, int> t = m;
        for (auto &&s : words)
        {
            for (auto &&c : s)
            {
                if (t.find(tolower(c)) != t.end())
                {
                    t[tolower(c)]--;
                }
            }
            if (test(t))
            {
                s.length() < res.length() ? res = s : res;
            }
            t = m;
        }
        return res;
    }
    bool test(map<char, int> &m)
    {
        for (auto &&d : m)
        {
            if (d.second > 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
