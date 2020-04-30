/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
#include <iostream>
#include <bitset>
using namespace std;

class Solution
{
public:
    int binaryGap(int N)
    {
        bitset<32> bit(N);
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (bit.test(i))
            {
                for (int j = i + 1; j < 32; ++j)
                {
                    if (bit.test(j))
                    {
                        ans = max(ans, j - i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
