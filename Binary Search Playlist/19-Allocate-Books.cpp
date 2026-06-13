#include <bits/stdc++.h>
using namespace std;

// Find the maximum element in the array.
// Minimum possible answer cannot be less than this,
// because one student must take that book.
int findMax(vector<int> &arr)
{

    int Max = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        Max = max(Max, arr[i]);
    }

    return Max;
}

// Check if all books can be allocated
// such that no student gets more than 'pages' pages.
bool isPossibleToAllocate(vector<int> &arr, int pages, int k)
{

    // Number of students required for this page limit
    int numStudentsRequired = 0;

    int currPages = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        // Current book can be assigned to the same student
        if (currPages + arr[i] <= pages)
        {

            currPages += arr[i];
        }

        // Need a new student
        else
        {

            numStudentsRequired++;
            currPages = arr[i];
        }
    }

    // Count the last student
    if (currPages)
        numStudentsRequired++;

    // If required students are within limit,
    // then this page limit is feasible.
    return numStudentsRequired <= k;
}

int findPages(vector<int> &arr, int k)
{

    // More students than books is invalid
    if (k > arr.size())
        return -1;

    // Binary Search on Answer

    // Lowest possible answer:
    // maximum pages in a single book
    int low = findMax(arr);

    // Highest possible answer:
    // one student gets all books
    int high = accumulate(arr.begin(), arr.end(), 0LL);

    int ans = -1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // Can we allocate books if
        // max pages per student = mid ?
        bool allocate = isPossibleToAllocate(arr, mid, k);

        if (allocate)
        {

            // mid works, store answer
            ans = mid;

            // Try to find a smaller valid answer
            high = mid - 1;
        }

        else
        {

            // mid is too small,
            // increase allowed pages
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> vec = {12, 34, 67, 90};
    int k = 2;

    cout << findPages(vec, k) << endl;

    return 0;
}