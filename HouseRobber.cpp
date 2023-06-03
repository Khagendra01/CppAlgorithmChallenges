#include <bits/stdc++.h>
using namespace std;

  int robBF(vector<int>& nums, int n)
    {
        if( n <= -1)
        {
            return 0;
        }

        return max(robBF(nums, n - 2) + nums[n], robBF(nums, n-1));
    }

    int rob(vector<int>& nums) {
        return robBF(nums, nums.size() - 1);
    }

    int main()
    {
        vector<int> nums = {2,7,9,3,1};
        cout << rob(nums);
    }