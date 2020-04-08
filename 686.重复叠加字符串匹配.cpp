/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        int count = 1;
        string temp = A;
        while (1)
        {
            if (A.find(B) != A.npos)
                break;
            else if (A.size() > B.size() + temp.size())
                return -1;
            {
                A += temp;
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end
