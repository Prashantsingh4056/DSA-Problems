#include <bits/stdc++.h>
using namespace std;

int findPow(int base, int pow)
{

    int prod = 1;

    for (int i = 0; i < pow; i++)
    {

        prod *= base;
    }

    return prod;
}

int nthRoot(int n, int m)
{

    if (m == 0)
        return 0;

    int low = 1;
    int high = m;
    int ans;

    while (low <= high)
    {

        long long mid = low + (high - low) / 2;

        if (findPow(mid, n) == m)
            return mid;

        else if (findPow(mid, n) < m)
        {
            low = mid + 1;
        }

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    //& n th root of m

    int n = 3;
    int m = 27;

    cout << nthRoot(n,m) << endl;

    return 0;
}