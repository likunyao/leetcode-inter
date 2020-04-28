/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
#include <string>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    string toGoatLatin(string S)
    {
        set<char> vawel{'a', 'e', 'i', 'o', 'u'};
        stringstream ss(S);
        string temp;
        string A = "a";
        string res = "";
        while (ss >> temp)
        {
            if (vawel.find(tolower(temp[0])) != vawel.end())
            {
                temp = temp + "ma" + A + " ";
                A += "a";
                res += temp;
            }
            else if (vawel.find(tolower(temp[0])) == vawel.end())
            {
                char c = temp[0];
                temp.erase(0, 1);
                temp = temp + c + "ma" + A + " ";
                A += "a";
                res += temp;
            }
        }
        res.erase(res.length() - 1, 1);
        return res;
    }
};
// @lc code=end
