#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr , int low , int mid , int high){

    vector<int> temp;

    // [low ... mid] 
    // [mid + 1 ... high]

    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){

        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low ; i <= high ; i++){
        arr[i] = temp[i - low];
    }

}

void mergeSort(vector<int>&arr , int low , int high){

    if(low >= high) return;
    int mid = low + (high - low) / 2;

    mergeSort(arr , low , mid);
    mergeSort(arr , mid + 1 , high);

    merge(arr , low , mid , high);
}

int main() {
    
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: \n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    // Time Complexity: O(n log n) in all cases (best, average, worst)
    // Space Complexity: O(n) due to the temporary array used for merging
    
    return 0;
}