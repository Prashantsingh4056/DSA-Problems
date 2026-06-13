#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{

    int low = 0;
    int high = nums.size() - 1;
    int Min = INT_MAX;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // If the Search space is already Sorted , return nums[low];
        if (nums[low] <= nums[high])
        {
            Min = min(Min, nums[low]);
            break;
        }

        // Step 1: Identify the Sorted Half

        // Check if Left part is Sorted
        if (nums[low] <= nums[mid])
        {

            // step 2: Take minimum from sorted part and move towards Un Sorted Part
            Min = min(Min, nums[low]);
            low = mid + 1;
        }

        // if Right part is Sorted
        else if (nums[mid] < nums[high])
        {

            // Take minimum from sorted part and move towards Un Sorted Part
            Min = min(Min, nums[mid]);
            high = mid - 1;
        }
    }

    return Min;
}

int main()
{

    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << endl;

    // another example
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums2) << endl;

    return 0;
}