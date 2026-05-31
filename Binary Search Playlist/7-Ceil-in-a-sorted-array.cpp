#include <bits/stdc++.h>
using namespace std;

int findCeil(vector<int>& arr, int x) {
        
        // We need to find the smallest element >= x
        // or Simply , find the lower bound of x
        
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            
            else low = mid + 1;
        }
        
        return ans;
    }

int main() {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << findCeil(vec , 5) << endl;

    return 0;
}