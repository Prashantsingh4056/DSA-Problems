#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x) {
        
        // We need to find largest number <= x
        
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= x){
                ans = mid;
                low = mid + 1;
            }
            
            else high = mid - 1;
        }
        
        return ans;
    }

int main() {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << findFloor(vec , 4) << endl;  
    return 0;
}