#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void rotate(vector<int> &nums, int k)
{
    int g_c_d = gcd(nums, k, nums.size());
    int a;

    for (int i = 0; i < g_c_d; i++)
    {
        int temp = nums[i];
        int j = i;
        while (true)
        {
            a = j + k;
            
        }
        nums[j] = temp;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    return 0;
}