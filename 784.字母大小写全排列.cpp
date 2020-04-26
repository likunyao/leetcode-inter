/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        res.push_back(S);
        vector<string> ts;
        for (size_t i = 0; i < S.length(); i++)
        {
            if (isalpha(S[i]))
            {
                for (auto &&s : res)
                {
                    string temp = s;
                    if (isupper(S[i]))
                    {
                        temp[i] = tolower(temp[i]);
                        ts.push_back(temp);
                    }
                    else
                    {
                        temp[i] = toupper(temp[i]);
                        ts.push_back(temp);
                    }
                }
                res.insert(res.end(), ts.begin(), ts.end());
                ts.clear();
            }
        }
        return res;
    }
};
// @lc code=end
