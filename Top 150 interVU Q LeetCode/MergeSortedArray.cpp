#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (n != 0)
    {
        if (m == 0)
        {
            nums1 = nums2;
        }
        else
        {
            vector<int> V(m+n);
            int i = 0, j = 0, k = 0;
            while (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    V[k++] = nums1[i++];
                }
                else
                {
                    V[k++] = nums2[j++];
                }
            }

            while (i < m)
            {
                V[k++] = nums1[i++];
            }
            while (j < n)
            {
                V[k++] = nums2[j++];
            }
            nums1 = V;
        }
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 5};
    vector<int> nums2 = {2, 4, 6, 8};
    cout << nums1.size() << endl;
    merge(nums1, nums1.size(), nums2, nums2.size());
    cout << nums1.size() << endl;
    for( int i =0; i < nums1.size(); i++){
        cout << nums1[i] << " ,";
    }
    cout << "All ok";
    return 0;
}