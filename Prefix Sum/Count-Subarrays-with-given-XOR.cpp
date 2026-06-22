#include <bits/stdc++.h>
using namespace std;


long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        int subarraysWithXorK = 0;
        
        // prefixXor , count
        unordered_map<int , int> mpp;


        mpp[0] = 1;
        
        int prefixXor = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            
            prefixXor ^= arr[i];
            
            int remove = prefixXor ^ k;
            
            // map access defaults to 0 if 'remove' doesn't exist
            subarraysWithXorK += mpp[remove];
            
            mpp[prefixXor]++;
        }
        
        return subarraysWithXorK;
    }

int main() {
    
    
    vector<int> arr = {4,2,2,6,4};
    int k = 6;

    cout << subarrayXor(arr , k) << endl;
    
    
    return 0;
}