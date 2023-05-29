#include <bits/stdc++.h>
using namespace std;

vector<int> MajorityElement(vector<int> &nums)
{
    vector<int> retu;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto i : m)
    {
        if (i.second > (nums.size() / 3))
        {
            retu.push_back(i.first);
        }
    }
    return retu;
}

vector<int> MajorityElementII(vector<int> &nums)
{
    int first = INT_MIN, fC = 0, second = INT_MIN, sC = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == first)
        {
            fC++;
        }
        else if (nums[i] == second)
        {
            sC++;
        }
        else if (fC == 0)
        {
            fC++;
            first = nums[i];
        }
        else if (sC == 0)
        {
            sC++;
            second = nums[i];
        }
        else
        {
            fC--;
            sC--;
        }
    }
    fC = 0;
    sC = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (first == nums[i])
        {
            fC++;
        }
        if (second == nums[i])
        {
            sC++;
        }
    }
    vector<int> returning;
    if (fC > nums.size() / 3)
    {
        returning.push_back(first);
    }

    if (sC > nums.size() / 3)
    {
        returning.push_back(second);
    }
    return returning;
}

int main()
{
    vector<int> nums = {2, 2, 2, 1, 1, 2, 2};

    nums = MajorityElementII(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ,";
    }
}