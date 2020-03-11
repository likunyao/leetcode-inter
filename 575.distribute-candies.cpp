/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {
        set<int> st(candies.begin(), candies.end());
        return min(st.size(), candies.size() / 2);
    }
};
// @lc code=end
