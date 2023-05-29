#include <bits/stdc++.h>
using namespace std;

int MajorityElement(vector<int> nums)
{
    int cnt = 0, cP;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            cP = nums[i];
            cnt = 1;
        }
        else
        {
            if (nums[i] == cP)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
    }
    return cP;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << MajorityElement(nums);
    return 0;
}