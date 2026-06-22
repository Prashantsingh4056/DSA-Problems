#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    unordered_map<int, int> mpp;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

        int remaining = target - nums[i];

        if (mpp.find(remaining) != mpp.end())
        {
            return {mpp[remaining], i};
        }

        mpp[nums[i]] = i;
    }

    return {};
}

int main()
{
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << twoSum(vec , 6)[0] << " " << twoSum(vec , 6)[1] << endl;

    return 0;
}