#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        //! check which part sorted

        //* Left part Sorted
        else if (nums[mid] >= nums[low])
        {

            // +target lies in the Left Sorted part
            if (nums[mid] > target && target >= nums[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        //* Right part Sorted
        else if (nums[mid] <= nums[high])
        {

            //+ target lies in the Right Sorted part
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{

    vector<int> vec = {8,9,10,1,2,3,4,5,6,7};

    cout << search(vec, 5) << endl;
    return 0;
}