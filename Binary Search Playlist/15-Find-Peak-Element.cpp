#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{

    int n = nums.size();

    if (nums.size() == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1;
    int high = n - 2;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // Peak Element
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
            return mid;
        }

        // increasing graph , peak will be found on right side
        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }

        // decreasing graph , peak will be found on left side
        else if (nums[mid] > nums[mid + 1])
        {
            high = mid - 1;
        }

        // to avoid the condition :  nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]

        else
            high = mid - 1;    // or we can write low = mid + 1;
    }

    return -1;
}

int main()
{

    vector<int> arr = {1,2,5,2,4,2,1};

    cout << findPeakElement(arr) << endl;
    return 0;
}