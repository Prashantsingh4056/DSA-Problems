#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // Max Heap
        // Top gives heaviest stone
        priority_queue<int> pq;

        for(int i = 0 ; i < stones.size() ; i++){
            pq.push(stones[i]);
        }

        // Continue until one or no stone remains
        while(pq.size() > 1){

            // Extract two heaviest stones
            int heaviestStone = pq.top();
            pq.pop();

            int secondHeaviestStone = pq.top();
            pq.pop();

            // If weights are different
            // new stone is formed
            if(heaviestStone != secondHeaviestStone){

                int resultantStoneWeight =
                    heaviestStone - secondHeaviestStone;

                pq.push(resultantStoneWeight);
            }

            // If equal, both stones are destroyed
        }

        // One stone left
        if(pq.size() == 1)
            return pq.top();

        // No stones left
        return 0;
    }
};


//* Revision Note 

// Two Largest Repeatedly
// → Max Heap

// Pop max
// Pop second max

// If equal:
//     discard both

// Else:
//     push difference