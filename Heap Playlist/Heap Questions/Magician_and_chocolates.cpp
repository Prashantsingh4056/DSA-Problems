#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(vector<int> &arr, int k){
    
    // Max Heap
    // Top always contains bag with maximum chocolates
    priority_queue<long long> pq;

    for(int i = 0 ; i < arr.size() ; i++)
        pq.push(arr[i]);

    long long maxChocolates = 0;

    // Perform operation exactly K times
    while(k-- && pq.size() > 0){

        // Pick bag with maximum chocolates
        int numChocolates = pq.top();
        pq.pop();

        // Eat all chocolates from that bag
        maxChocolates += numChocolates;

        // Magician refills bag with floor(x/2)
        pq.push(numChocolates / 2);
    }

    return maxChocolates;
}

//* Revision Note

// Largest Element Repeatedly
// → Max Heap

// Take largest
// Answer += largest
// Push largest/2 back
// Repeat K times