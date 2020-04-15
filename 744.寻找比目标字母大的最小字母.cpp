/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (auto &&c : letters)
        {
            if (c > target)
            {
                return c;
            }
        }
        return letters[0];
    }
};
// @lc code=end
