/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution
{
    int binary_search(MountainArray &mountain, int target, int l, int r, int key(int))
    {
        target = key(target);
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cur = key(mountain.get(mid));
            if (cur == target)
                return mid;
            else if (cur < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int l = 0, r = mountainArr.length() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;
        int index = binary_search(mountainArr, target, 0, peak, [](int x) -> int { return x; });
        if (index != -1)
            return index;
        return binary_search(mountainArr, target, peak + 1, mountainArr.length() - 1, [](int x) -> int { return -x; });
    }
};
// @lc code=end
