#include <bits/stdc++.h>
using namespace std;

void HeapifyMax(vector<int>& arr , int index , int n){

    int largest = index;
    int left = 2 * index + 1;    // left child
    int right = 2 * index + 2;   // right child


    // assign largest to max element's index
    if(left < n && arr[left] > arr[largest]) largest = left;     
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != index){

        swap(arr[index] , arr[largest]);
        HeapifyMax(arr , largest , n);
    }
}

void buildMaxHeap(vector<int>& arr){


    //* step down

    int n = arr.size();

    for(int i = n / 2 - 1 ; i >= 0 ; i--){

        HeapifyMax(arr , i , n); 
    }
}

void sortArray(vector<int>& arr){

    int n = arr.size();

    for(int i = n - 1 ; i > 0 ; i--){

        swap(arr[i] , arr[0]);    // swap the last element with the max element at the top of the Heap
        
        // Then apply Heapify to get the Largest element at the top of the Heap
        // Heapify(array , for 0 index , current size of the array)
        HeapifyMax(arr , 0 , i);
    }   
}

int main() {

    // Procedure to perform Heap Sort

    // => Convert Array to Max Heap
    // => MaxHeap to sorted Array
    
    vector<int> arr = {33,45,2,52,34,2,43,1,34,12,4,2,432};
    
    //* Step 1 
    buildMaxHeap(arr);

    //* Step 2
    sortArray(arr);

    for(int i = 0 ; i < arr.size() ; i++){

        cout << arr[i] << " ";
    }

    cout << endl;

    //! T.C. => O(N logN)
    //! S.C. => O(N) for recursion stack space

    //! iterative way : S.C.  => (1) using while loop

    return 0;
}