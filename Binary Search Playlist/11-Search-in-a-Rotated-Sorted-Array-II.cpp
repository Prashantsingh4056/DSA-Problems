#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return true;
        }

        // Edge Case for duplicates in array
        else if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }

        // Check if the Left Part is Sorted
        else if (nums[low] <= nums[mid])
        {

            // Check if the target lies in the Sorted Part
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Check if the Right Part is Sorted
        else
        {

            // Check if the target lies in the Sorted Part
            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> vec = {3,3,3,3,2,3,3,3,3,3,3};

    cout << search(vec , 2) << endl;

    return 0;
}