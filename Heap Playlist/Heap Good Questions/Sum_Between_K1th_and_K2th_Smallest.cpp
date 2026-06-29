#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        
        
        // here we will simply find the sum of K1 elements and K2 elements and then subtract them 
        
        // create two max Heaps
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        
        
        // track the sum of first K1 elements
        int sum1 = 0;
        
        // track the sum of first K2 - 1 elements
        int sum2 = 0;
        
        // insert K1 elements into pq1
        for(int i = 0 ; i < K1 ; i++){
            pq1.push(A[i]);
            sum1 += A[i];
        }
        
        // insert K2 - 1 elements into pq2
        for(int i = 0 ; i < K2 - 1 ; i++){
            pq2.push(A[i]);
            sum2 += A[i];
        }
        
        
        // Maintain the K1 smallest elements and their sum in pq1 throughout the array
        for(int i = K1 ; i < N ; i++){
            
            if(pq1.top() > A[i]){
                
                sum1 -= pq1.top();
                pq1.pop();
                
                pq1.push(A[i]);
                sum1 += A[i];
            }
        }
        
        // Maintain the K2 - 1 smallest elements and their sum in pq2 throughout the array
        for(int i = K2 - 1 ; i < N ; i++){
            
            if(pq2.top() > A[i]){
                
                sum2 -= pq2.top();
                pq2.pop();
                
                pq2.push(A[i]);
                sum2 += A[i];
            }
        }
        
        // Sum of elements between k1'th and k2'th smallest elements excluding k1th and k2th 
        return sum2 - sum1;
    }
};