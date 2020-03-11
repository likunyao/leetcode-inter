/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        unordered_map<char, int> mp{
            {'q', 1},
            {'w', 1},
            {'e', 1},
            {'r', 1},
            {'t', 1},
            {'y', 1},
            {'u', 1},
            {'i', 1},
            {'o', 1},
            {'p', 1},
            {'a', 2},
            {'s', 2},
            {'d', 2},
            {'f', 2},
            {'g', 2},
            {'h', 2},
            {'j', 2},
            {'k', 2},
            {'l', 2},
            {'z', 3},
            {'x', 3},
            {'c', 3},
            {'v', 3},
            {'b', 3},
            {'n', 3},
            {'m', 3},
        };
        vector<string> res;
        for (auto &&s : words)
        {
            int tmp;
            for (size_t i = 0, tmp = mp[towlower(s[0])]; i < s.length(); i++)
            {
                if (mp[towlower(s[i])] != tmp)
                {
                    break;
                }
                if (i == s.length() - 1)
                {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};
// @lc code=end
