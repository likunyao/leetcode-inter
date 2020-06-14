/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 *
 * [1300] 转变数组后最接近目标值的数组和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        int Min = target / arr.size();
        int sum, res, tmp = target;
        for (int i = Min; i < target; i++)
        {
            sum = 0;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j] > i)
                {
                    sum += i;
                }
                else
                {
                    sum += arr[j];
                }
            }
            int foo = abs(sum - target);
            if (foo < tmp)
            {
                tmp = foo;
                res = i;
            }
            else if (foo > tmp)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
