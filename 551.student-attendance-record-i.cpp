/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int absent = 0;
        int late = 0;
        for (auto &&c : s)
        {
            if (c == 'A')
            {
                late = 0;
                absent++;
                if (absent > 1)
                {
                    return false;
                }
            }
            else if (c == 'L')
            {
                late++;
                if (late > 2)
                {
                    return false;
                }
            }
            else
            {
                late = 0;
            }
        }
        return true;
    }
};
// @lc code=end
