#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{

    int n = nums.size();
    int low = 1;
    int high = n - 2;

    if (nums.size() == 1)
        return nums[0];

    if (nums[0] != nums[1])
        return nums[0];

    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // if the mid element is the sigle element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        // Check which side contains the Single element
        else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            low = mid + 1;
        }

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    
    vector<int> vec = {1,1,2,3,3,4,4,5,5,6,6};
    cout << singleNonDuplicate(vec) << endl;

    return 0;
}