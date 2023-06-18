#include <bits/stdc++.h>
using namespace std;

  int robBF(vector<int>& nums, int n, vector<int>& cache)
    {
        if( n <= -1)
        {
            return 0;
        }

        if(cache[n] != -1)
        {
            return cache[n];
        }

        cache[n] = max(robBF(nums, n - 2, cache) + nums[n], robBF(nums, n-1, cache));

        return cache[n];
    }

    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        return robBF(nums, nums.size() - 1, cache);
    }

    int main()
    {
        vector<int> nums = {2,7,9,3,1};
        cout << rob(nums);
    }