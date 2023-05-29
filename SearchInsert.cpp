#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    int mid = 0;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        if (target > nums[mid])
        {
            lo = mid + 1;
        }
        if (target < nums[mid])
        {
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    vector<int> nums = {1,3,5,6};
    cout << searchInsert(nums, 2);
    return 0;
}