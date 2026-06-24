#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> pq;

        // Insert all gift piles into Max Heap
        for(int i = 0 ; i < gifts.size() ; i++){
            pq.push(gifts[i]);
        }

        // Perform K operations
        while(k-- && !pq.empty()){

            // Richest pile
            int maxGifts = pq.top();
            pq.pop();

            // Leave behind floor(sqrt(maxGifts))
            int reducedGifts = floor(sqrt(maxGifts));

            // Insert updated pile back
            pq.push(reducedGifts);
        }

        long long remainingGifts = 0;

        // Sum all remaining piles
        while(!pq.empty()){

            remainingGifts += pq.top();
            pq.pop();
        }

        return remainingGifts;
    }
};


//* Revision Note

// Largest Element Repeatedly
// → Max Heap

// Pop largest
// Transform it
// Push back
// Repeat K times