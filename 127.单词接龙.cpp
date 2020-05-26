/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int wordSize = beginWord.length();
        int listSize = wordList.size();
        vector<unordered_set<string>> level(listSize + 1);
        vector<int> flag(listSize, 0);
        level[0].insert(beginWord);
        for (int i = 0; i < level.size(); i++)
        {
            for (auto &&s : level[i])
            {
                for (int j = 0; j < listSize; j++)
                {
                    if (flag[j] == 1)
                    {
                        continue;
                    }
                    int l = 0, cnt = 0;
                    while (l < wordSize && cnt <= 1)
                    {
                        if (s[l] != wordList[j][l])
                        {
                            cnt++;
                        }
                        l++;
                    }
                    if (cnt == 1)
                    {
                        flag[j] = 1;
                        level[i + 1].insert(wordList[j]);
                        if (wordList[j] == endWord)
                        {
                            return i + 2;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
