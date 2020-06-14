/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    const vector<int> fac = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

public:
    string getPermutation(int n, int k)
    {
        // string res;
        // string s = string("123456789").substr(0, n);
        // for (int i = 1; i < k; i++)
        // {
        //     next_permutation(s.begin(), s.end());
        // }
        // return s;
        string res;
        string s = string("123456789").substr(0, n);
        k--;
        while (k > 0)
        {
            int i = k / fac[n - 1];
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac[n - 1];
            n--;
        }
        return res + s;
    }
};
// @lc code=end
