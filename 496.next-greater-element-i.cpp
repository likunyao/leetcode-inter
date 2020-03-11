/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        int index = 0;
        for (auto &&item : nums2)
        {
            mp[item] = index++;
        }
        for (size_t i = 0; i < nums1.size(); i++)
        {
            for (size_t j = mp[nums1[i]]; j < nums2.size(); j++)
            {
                if (nums1[i] < nums2[j])
                {
                    res.push_back(nums2[j]);
                    break;
                }
                if (j == nums2.size() - 1)
                {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
