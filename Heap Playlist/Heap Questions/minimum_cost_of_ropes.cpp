#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {

        // Min Heap:
        // Top always contains the smallest rope
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Insert all ropes into Min Heap
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
        }

        int totalCost = 0;

        // Keep joining ropes until only one rope remains
        while (pq.size() != 1)
        {

            // Extract the two smallest ropes
            int minElement = pq.top();
            pq.pop();

            int secondMinElement = pq.top();
            pq.pop();

            // Cost of joining two ropes
            int cost = minElement + secondMinElement;

            totalCost += cost;

            // New rope formed after joining
            // may participate in future joins
            pq.push(cost);
        }

        return totalCost;
    }
};


//* Revision Note

// Two Smallest Repeatedly
// → Min Heap

// 1. Pop smallest
// 2. Pop second smallest
// 3. Add cost
// 4. Push combined rope back