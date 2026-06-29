#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

void heapify(vector<int>& arr , int index){

    int n = arr.size();

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Find the largest among parent and children
    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    // If parent is not the largest,
    // swap and restore heap property
    if(largest != index){

        swap(arr[largest] , arr[index]);

        heapify(arr , largest);
    }
}

void buildMaxHeap(vector<int>& arr){

    int n = arr.size();

    // Bottom-up Heap Construction
    // Start from last non-leaf node
    for(int i = n/2 - 1 ; i >= 0 ; i--){

        heapify(arr , i);
    }
}

vector<int> mergeHeap(int n, int m,
                      vector<int> &arr1,
                      vector<int> &arr2) {

    vector<int> ans;

    // Copy first heap
    for(int i = 0 ; i < n ; i++){
        ans.push_back(arr1[i]);
    }

    // Copy second heap
    for(int i = 0 ; i < m ; i++){
        ans.push_back(arr2[i]);
    }

    // Convert merged array into Max Heap
    buildMaxHeap(ans);

    return ans;
}


// Merge Two Heaps

// Step 1
// Copy Heap1

// Step 2
// Copy Heap2

// Step 3
// Build Max Heap

// Done.