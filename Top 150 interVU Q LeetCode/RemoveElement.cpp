 #include <bits/stdc++.h>
 using namespace std;

 int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for( int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
    int main()
    {
        vector<int> nums = {1, 2, 3, 4, 5, 2, 4, 5, 5, 2};
        cout << removeElement( nums, 2);
    }