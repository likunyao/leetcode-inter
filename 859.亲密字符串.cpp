/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length())
        {
            return false;
        }
        vector<int> idx;
        for (size_t i = 0; i < A.length(); i++)
        {
            if (A[i] != B[i])
            {
                idx.push_back(i);
            }
        }
        if (idx.size() == 2)
        {
            char temp = A[idx[0]];
            A[idx[0]] = A[idx[1]];
            A[idx[1]] = temp;
            return A == B;
        }
        if (idx.size() == 0)
        {
            set<char> t(A.begin(), A.end());
            return t.size() < A.size();
        }
        return false;
    }
};
// @lc code=end
