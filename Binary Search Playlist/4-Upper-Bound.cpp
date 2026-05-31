#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr , int x){

    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        
        else low = mid + 1;
    }

    return ans;
}

int main() {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << upperBound(vec , 9);

    return 0;
}