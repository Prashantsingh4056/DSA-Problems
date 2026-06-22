#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int k)
{

    unordered_map<int, int> mpp;

    // prefixSum , index
    mpp[0] = -1;

    int maxLen = 0;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        prefixSum += arr[i];

        int remove = prefixSum - k;

        // if the (prefixSum - k) exists in the map , take the new updated length
        if (mpp.find(remove) != mpp.end())
        {
            maxLen = max(maxLen, (i - mpp[remove]));
        }

        // if prefixSum not present in the map , then only push in the map
        if (mpp.find(prefixSum) == mpp.end())
        {
            mpp[prefixSum] = i;
        }
    }

    return maxLen;
}

int main()
{
    
    vector<int> arr = {10 , 5 , 2  , 7  , 1 , -10};
    int k = 15;

    cout << longestSubarray(arr , k) << endl;

    return 0;
}