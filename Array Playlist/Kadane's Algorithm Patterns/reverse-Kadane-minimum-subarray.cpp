#include <bits/stdc++.h>
using namespace std;


int smallestSumSubarray(vector<int> &a)
{

    int n = a.size();

    // Reverse Kadane's algorithm

    int minSum = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += a[i];

        minSum = min(minSum, sum);

        if (sum > 0)
            sum = 0;
    }

    return minSum;
}

int main()
{
    
    vector<int> vec = {3 , -4 , 2 , -3 , -1 , 7 , 5};

    cout << smallestSumSubarray(vec) << endl;

    return 0;
}