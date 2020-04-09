/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> group;
        int last = 1;
        int res = 0;
        for (size_t i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                last++;
            }
            else
            {
                group.push_back(last);
                last = 1;
            }
        }
        group.push_back(last);
        for (size_t i = 0; i < group.size() - 1; i++)
        {
            res += min(group[i], group[i + 1]);
        }
        return res;
    }
};
// @lc code=end
