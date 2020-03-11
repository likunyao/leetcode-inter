/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        S.erase(remove(S.begin(), S.end(), '-'), S.end());
        for (auto &&c : S)
        {
            c = toupper(c);
        }
        int head = S.length() % K;
        string res;
        res += S.substr(0, head);
        int count = S.length() / K;
        for (size_t i = 0; i < count; i++)
        {
            if (i == 0 && head == 0)
            {
                res += S.substr(head + i * K, K);
                continue;
            }
            res += '-';
            res += S.substr(head + i * K, K);
        }
        return res;
    }
};
// @lc code=end
