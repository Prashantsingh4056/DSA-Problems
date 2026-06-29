#include <bits/stdc++.h>
using namespace std;

// Q. Find the Kth element in a Matrix

// let K = 6

// w _____________________
// w | 16 | 28 | 60 | 64 |
// w | 22 | 41 | 63 | 91 |
// w | 27 | 50 | 87 | 93 |
// w | 36 | 78 | 87 | 94 |
// w ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

// Kth element : 41

//* ___________________________________________ Approach 1 : ______________________________________

//^ Take all the elements to a 1 D array and sort it get kth element
//^ T.C. => N²logN

//* ___________________________________________ Approach 2 : _______________________________________

//^ Make min heap of the matrix in a 1D array
//^ step down method :  O(N²)

//^ deletion : K log(N²) => K log(N)

//^ overall : N² + K log(N)

//* ___________________________________________ Approach 3 : __________________________________

//^ First push all the first column elements to priority queue (Min Heap)
//^ then remove the smallest one and push the next element in that same row
//^ again pop the top element of priority queue and push the element from that row until you get the kth smallest

// todo  Here we need to store 3 things to priority queue => (data , row , column) ==> pair<int , pair<int , int>>

//^ T.C. =>  N + K log(N)

//! ==> we can push the elements to priority queue in O(N) too =>

//+ => priority_queue<int> p(vec.begin() , vec.end())   ==> T.C. => O(N)

//* vec[N]
//+ => array --> priority_queue<int> p(vec , vec + N)

// w _______________________________________ <== Code ==> _________________________________________

int kthSmallest(vector<vector<int>> &mat, int k)
{

    int n = mat.size();

    // Create Min heap
    // store pair<int , pair<int , int>> in priority queue

    vector<pair<int, pair<int, int>>> firstCol;

    for (int i = 0; i < n; i++)
        firstCol.push_back(make_pair(mat[i][0], make_pair(i, 0)));

    // push the first column elements to the priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(firstCol.begin(), firstCol.end());

    // we pop the element and take into this variable
    pair<int, pair<int, int>> Element;

    int ans;

    // run the loop k times to get the kth smallest
    while (k--)
    {

        Element = pq.top();
        pq.pop();

        ans = Element.first;

        int i = Element.second.first;
        int j = Element.second.second;

        if (j + 1 < n)
            pq.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}

//* ___________________________________________ Approach 4 : _______________________________________

// w _____________________
// w | 16 | 28 | 60 | 64 |
// w | 22 | 41 | 63 | 91 |
// w | 27 | 50 | 87 | 93 |
// w | 36 | 78 | 87 | 94 |
// w ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//^ push the first element (16) to priority_queue
//^ pop the element 16 and push 28 , 22 into priority queue
//^ pop the smallest (22) and push 27 , 41 to pq
//^ pop the smallest (27) and push 50 , 36
//^ pop the smallest (28) and push 60 , (41 already inserted so  don't insert it again)
//^ pop the smallest (36) and push 78
//^ pop the smallest (41) and this will be 6th smallest

//* ___________________________________________ Approach 5 : Binary Search __________________________

//* This is similar to matrix median Problem , here we need to find the kth element instead of middle

int upperBound(vector<int> &arr, int x)
{

    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
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

int findNumberOfElements(int mid, vector<vector<int>> &matrix)
{

    int numElements = 0;

    for (int i = 0; i < matrix.size(); i++)
    {

        numElements += upperBound(matrix[i], mid);
    }

    return numElements;
}

int kthSmallest(vector<vector<int>> &matrix, int k)
{

    // This Problem is similar to matrix median

    int n = matrix.size();

    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    int ans;

    while (low <= high)
    {

        long long mid = low + (high - low) / 2;

        int numElements = findNumberOfElements(mid, matrix);

        if (numElements < k)
        {

            low = mid + 1;
        }

        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}