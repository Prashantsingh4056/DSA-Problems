#include <bits/stdc++.h>
using namespace std;


class KthLargest {
public:

    // Min Heap stores K largest elements
    priority_queue<int,
                   vector<int>,
                   greater<int>> pq;

    int K;

    KthLargest(int k, vector<int>& nums) {

        K = k;

        // Build heap
        for(int i = 0 ; i < nums.size() ; i++){

            pq.push(nums[i]);

            // Keep only K largest elements
            if(pq.size() > K)
                pq.pop();
        }
    }

    int add(int val) {

        // Insert new element
        pq.push(val);

        // Remove extra smallest element
        if(pq.size() > K)
            pq.pop();

        // Top = Kth largest
        return pq.top();
    }
};

//^ Numbers keep arriving.

//^ Need Kth largest after every insertion.

//^ Maintain only K largest elements.