#include <bits/stdc++.h>
using namespace std;

//* Kth smallest => Max Heap
//* Kth largest => Min Heap

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        // Max Heap
        
        priority_queue<int> pq;
        
        // Insert first K elements
        // These are currently the K smallest candidates
        for(int i = 0 ; i < k ; i++){
            pq.push(arr[i]);
        }
        
        // Maintain K smallest elements throughout the array
        for(int i = k ; i < arr.size() ; i++){
            
            // If current element is smaller than the
            // largest element among our K smallest elements
            if(pq.top() > arr[i]){
                
                // Remove largest element
                pq.pop();
                
                // Insert smaller element
                pq.push(arr[i]);
            }
        }
        
        // Heap contains K smallest elements
        // Largest among them = Kth smallest
        return pq.top();
    }
};


//^ Maintain the K smallest elements seen so far.

//^ Among those K elements:

//^ largest element = Kth smallest

