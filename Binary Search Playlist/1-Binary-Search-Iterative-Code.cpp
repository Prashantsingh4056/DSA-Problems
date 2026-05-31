#include <bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> arr, int target)
{

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    cout << Binary_Search(vec, target) << endl;

    return 0;
}