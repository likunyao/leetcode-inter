/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        vector<string> res;
        int indexSum = INT_MAX;
        map<string, int> mmp;
        for (size_t i = 0; i < list1.size(); i++)
        {
            mmp[list1[i]] = i;
        }
        for (size_t j = 0; j < list2.size(); j++)
        {
            if (mmp.count(list2[j]))
            {
                if (j + mmp[list2[j]] == indexSum)
                {
                    res.push_back(list2[j]);
                }
                else if (j + mmp[list2[j]] < indexSum)
                {
                    res.clear();
                    indexSum = j + mmp[list2[j]];
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
