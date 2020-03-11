/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<string> res(nums.size());
        int index = 0;
        for (auto &&i : nums)
        {
            mp[i] = index++;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        for (size_t i = 0; i < nums.size(); i++)
        {
            switch (i)
            {
            case 0:
                res[mp[nums[i]]] = "Gold Medal";
                break;
            case 1:
                res[mp[nums[i]]] = "Silver Medal";
                break;
            case 2:
                res[mp[nums[i]]] = "Bronze Medal";
                break;
            default:
                res[mp[nums[i]]] = to_string(i + 1);
                break;
            }
        }
        return res;
    }
};
// @lc code=end
