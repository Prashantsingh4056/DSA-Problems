#include <bits/stdc++.h>
using namespace std;


//*  Solve Here : 
//todo   https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
//todo   https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473

// Finds the minimum element in the matrix (first element of the first column has the absolute minimum)
int findMin(vector<vector<int>> &matrix)
{
    int Min = INT_MAX;
    for (int i = 0; i < matrix.size(); i++)
    {
        Min = min(Min, matrix[i][0]); // Check the first element of each sorted row
    }
    return Min;
}

// Finds the maximum element in the matrix (last element of each row holds potential absolute maximums)
int findMax(vector<vector<int>> &matrix)
{
    int Max = INT_MIN;
    int n = matrix[0].size(); // Number of columns
    for (int i = 0; i < matrix.size(); i++)
    {
        Max = max(Max, matrix[i][n - 1]); // Check the last element of each sorted row
    }
    return Max;
}

// Standard Upper Bound: Finds the index of the first element strictly GREATER than x
int upperBound(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default to array size if no element is strictly greater than x

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
        {
            ans = mid;      // Found a candidate strictly greater than x, store index
            high = mid - 1; // Look left for a smaller valid index
        }
        else
        {
            low = mid + 1; // Element is <= x, discard the left half
        }
    }
    return ans;
}

// Counts how many elements in the entire matrix are LESS THAN OR EQUAL TO 'mid'
int findNumOfElements(int mid, vector<vector<int>> &matrix, int m, int n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        // upperBound returns the index of the first element > mid,
        // which perfectly equals the count of elements <= mid in that row.
        count += upperBound(matrix[i], mid);
    }
    return count;
}

// Finds the median of the matrix using Binary Search on Answer range [Min, Max]
int median(vector<vector<int>> &matrix, int m, int n)
{
    int low = findMin(matrix);  // Starting range boundary
    int high = findMax(matrix); // Ending range boundary
    int ans = -1;               // Initialized safely to track the best median candidate

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int numElementsLessOrEqualTo = findNumOfElements(mid, matrix, m, n);

        // A median must have STRICTLY MORE than half of total elements less than or equal to it
        if (numElementsLessOrEqualTo <= (m * n) / 2)
        {
            // mid is too small to be the median (not enough elements behind it)
            low = mid + 1;
        }
        else
        {
            // mid is a valid median candidate (has enough elements behind it)
            ans = mid;      // Store this valid candidate
            high = mid - 1; // Look left to check if a smaller number satisfies this too
        }
    }
    return ans; // 'ans' will now hold the exact, smallest valid median value
}

int main()
{

    return 0;
}