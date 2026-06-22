#include <bits/stdc++.h>
using namespace std;

//* There are two questions very similar to this :

// todo https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// todo https://leetcode.com/problems/split-array-largest-sum/

//* Painters Partition : ---------------------------------------------------------------------

int countPainters(vector<int> &arr, int walls)
{

    int numPainters = 0;

    int numWalls = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        if (numWalls + arr[i] <= walls)
        {

            numWalls += arr[i];
        }

        else
        {

            numPainters++;
            numWalls = arr[i];
        }
    }

    if (numWalls)
        numPainters++;

    return numPainters;
}

int minTime(vector<int> &arr, int k)
{
    // code here

    int n = arr.size();

    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high)
    {

        long long mid = low + (high - low) / 2;

        int painters = countPainters(arr, mid);

        if (painters <= k)
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {

            low = mid + 1;
        }
    }

    return ans;
}

//* Split Array Largest Sum -------------------------------------------------------------------

int findSubarraysFormed(vector<int> &nums, int sum)
{

    int numSubarrays = 0;
    int currSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (currSum + nums[i] <= sum)
        {

            currSum += nums[i];
        }

        else
        {

            numSubarrays++;
            currSum = nums[i];
        }
    }

    if (currSum)
        numSubarrays++;

    return numSubarrays;
}

int splitArray(vector<int> &nums, int k)
{

    int n = nums.size();

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        int numSubarrays = findSubarraysFormed(nums, mid);

        // if number of subarrays formed are less than k , we keep reducing mid so that we can reach upto k subarrays
        if (numSubarrays <= k)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}
int main()
{
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    return 0;
}