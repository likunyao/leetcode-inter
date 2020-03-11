/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int maxLen = 0;
        for (size_t i = 0; i < houses.size(); i++)
        {
            int lo = 0, hi = heaters.size() - 1;
            int tmp = INT_MAX;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (heaters[mid] == houses[i])
                {
                    tmp = 0;
                    break;
                }
                else if (heaters[mid] > houses[i])
                {
                    tmp = min(tmp, heaters[mid] - houses[i]);
                    hi = mid - 1;
                }
                else if (heaters[mid] < houses[i])
                {
                    tmp = min(tmp, houses[i] - heaters[mid]);
                    lo = mid + 1;
                }
            }
            maxLen = max(maxLen, tmp);
        }
        return maxLen;
    }
};
// @lc code=end
