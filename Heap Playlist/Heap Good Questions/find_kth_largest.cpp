#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // Min Heap
        priority_queue<int,
                       vector<int>,
                       greater<int>> pq;

        // Insert first K elements
        for(int i = 0 ; i < k ; i++){
            pq.push(nums[i]);
        }

        // Maintain K largest elements
        for(int i = k ; i < nums.size() ; i++){

            // Current element is larger than
            // smallest among K largest elements
            if(pq.top() < nums[i]){

                // Remove smallest
                pq.pop();

                // Insert larger element
                pq.push(nums[i]);
            }
        }

        // Heap contains K largest elements
        // Smallest among them = Kth largest
        return pq.top();
    }
};


//^ Maintain K largest elements.

//^ Among them:

//^ smallest element = Kth largest