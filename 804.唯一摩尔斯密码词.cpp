/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> w = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        string temp = "";
        vector<string> save;
        for (auto &&s : words)
        {
            for (auto &&c : s)
            {
                temp += w[c - 'a'];
            }
            save.push_back(temp);
            temp.clear();
        }
        set<string> filter(save.begin(), save.end());
        save.assign(filter.begin(), filter.end());
        return save.size();
    }
};
// @lc code=end
