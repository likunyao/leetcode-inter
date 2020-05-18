/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits == "")
        {
            return res;
        }
        unordered_map<char, string> table = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        dfs(digits, table, "", res, 0);
        return res;
    }

    void dfs(const string &digits, unordered_map<char, string> &table, string temp, vector<string> &res, int n)
    {
        if (temp.length() == digits.length())
        {
            res.push_back(temp);
            return;
        }
        for (auto &&c : table[digits[n]])
        {
            temp += c;
            dfs(digits, table, temp, res, n + 1);
            temp.pop_back();
        }
        return;
    }
};
// @lc code=end
