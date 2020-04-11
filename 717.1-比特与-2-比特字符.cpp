/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int sum = 0, i = bits.size() - 2;
        while (i >= 0 && bits[i] == 1)
        {
            ++sum;
            --i;
        }
        return sum % 2 == 0;
    }
};
// @lc code=end
