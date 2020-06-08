/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.length() <= 1)
        {
            return 0;
        }
        vector<int> mark(s.length(), 0);
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (st.empty())
                {
                    mark[i] = 1;
                }
                else
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            mark[st.top()] = 1;
            st.pop();
        }
        int res = 0;
        int cnt = 0;
        for (auto &&n : mark)
        {
            if (n == 0)
            {
                cnt++;
                res = max(res, cnt);
            }
            else
            {
                cnt = 0;
            }
        }
        return res;
    }
};
// @lc code=end
