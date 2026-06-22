#include <bits/stdc++.h>
using namespace std;

//todo :

//todo https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?envType=problem-list-v2&envId=binary-search

int findMin(vector<int> &nums)
{

    int n = nums.size();

    int low = 0;
    int high = nums.size() - 1;
    int ans = min(nums[0], nums[n - 1]);

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // if all the three low , mid , high elements become equal , try shriking the window from both ends
        if (nums[low] == nums[mid] && nums[mid] == nums[high] && high - low > 1)
        {
            low++;
            high--;
            continue;
        }

        // check if left part is Sorted
        else if (nums[low] <= nums[mid])
        {

            // take the minimum from left sorted part and move to right part
            ans = min(ans, nums[low]);
            low = mid + 1;
        }

        // if the right part is Sorted
        else if (nums[mid] <= nums[high])
        {

            // take the minimum from right Sorted part and move to left part
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }

    // return the final min element
    return ans;
}

int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    return 0;
}