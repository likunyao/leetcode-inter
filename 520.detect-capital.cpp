/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int LastUp = -1;
        int LastLow = -1;
        int index = 0;
        for (auto &&c : word)
        {
            if (islower(c))
            {
                LastLow = index;
            }
            else
            {
                LastUp = index;
            }
            index++;
        }
        if (LastUp >= 1 && LastLow >= 0)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
