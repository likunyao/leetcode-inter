/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        for (auto &&c : paragraph)
        {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        stringstream ss(paragraph);
        string temp, res;
        int max = INT32_MIN;
        unordered_map<string, int> mmp;
        unordered_set<string> ban;
        for (auto &&s : banned)
        {
            ban.insert(s);
        }
        while (ss >> temp)
        {
            if (ban.find(temp) == ban.end())
            {
                mmp[temp]++;
                if (mmp[temp] > max)
                {
                    max = mmp[temp];
                    res = temp;
                }
            }
        }
        return res;
    }
};
// @lc code=end
