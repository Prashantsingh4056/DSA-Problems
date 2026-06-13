#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n) {
        
        int low = 0;
        int high = n;
        int ans;

        while(low <= high){

            long long mid = low + (high - low) / 2;

            if((mid * (mid + 1)) / 2 == n){
                return mid;
            }
            
            // Find maximum mid such that condition is true.
            else if((mid * (mid + 1)) / 2 < n){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }

        return ans;
    }

int main() {
    
    // *
    // * *
    // * *    -> incomplete Row
    cout << arrangeCoins(5) << endl;
    
    
    return 0;
}