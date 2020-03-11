/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        if (moves == "")
        {
            return true;
        }
        map<char, int> mmp;
        for (auto &&c : moves)
        {
            mmp[c]++;
        }
        if (mmp['L'] != mmp['R'] || mmp['U'] != mmp['D'])
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
