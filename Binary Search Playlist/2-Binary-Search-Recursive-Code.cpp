#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr , int low , int high , int target){
    
    if(low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if(arr[mid] == target) return mid;
    
    else if(arr[mid] > target) return binary_search(arr , low , mid - 1 , target);
    
    else return binary_search(arr , mid + 1 , high , target);
    
    return -1;
}

int main(){
    
    vector<int> arr = {1 , 4 , 5 , 8, 12 , 34 , 56 , 78, 79};
    
    int low = 0;
    int high = arr.size() - 1;
    int target = 13;
    
    cout << binary_search(arr , low , high , target) << endl;
    
    return 0;
}