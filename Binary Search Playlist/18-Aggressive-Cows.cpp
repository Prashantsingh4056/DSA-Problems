#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/aggressive-cows/1

bool canPlaceCows(int dist, vector<int> &stalls, int k)
{

    int numCows = 1; // 1 cow already placed at start
    int lastStall = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {

        if (stalls[i] - lastStall >= dist)
        {
            numCows++;   // Place the cow

            lastStall = stalls[i];   // Track the last stall where the cow is placed 
        }
    }

    if (numCows >= k)
        return true;

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{

    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    int ans;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (canPlaceCows(mid, stalls, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> vec = {1, 2, 4, 8, 9};
    int k = 3;

    cout << aggressiveCows(vec, k) << endl;

    return 0;
}
