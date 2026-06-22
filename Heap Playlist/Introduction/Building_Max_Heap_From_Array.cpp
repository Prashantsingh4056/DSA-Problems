#include <bits/stdc++.h>
using namespace std;


void HeapifyMax(vector<int>& arr , int index){

    int n = arr.size();

    int largest = index;
    int left = 2 * index + 1;    // left child
    int right = 2 * index + 2;   // right child


    // assign largest to max element's index
    if(left < n && arr[left] > arr[largest]) largest = left;     
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != index){

        swap(arr[index] , arr[largest]);
        HeapifyMax(arr , largest);
    }
}


void HeapifyMin(vector<int>& arr , int index){

    int n = arr.size();

    int smallest = index;
    int left = 2 * index + 1;    // left child
    int right = 2 * index + 2;    // right child

    // assign smallest to the min element's index
    if(left < n && arr[left] < arr[smallest]) smallest = left;
    if(right < n && arr[right] < arr[smallest]) smallest = right;

    // if the index is not the smallest , then Heapify 
    if(smallest != index){

        swap(arr[index] , arr[smallest]);
        HeapifyMin(arr , smallest);
    }
}

//*  T.C. => O(N)    => for Top Down approach
//*  S.C. => O(logN)

void buildMaxHeap(vector<int>& arr){


    //* step down

    int n = arr.size();

    for(int i = n / 2 - 1 ; i >= 0 ; i--){

        HeapifyMax(arr , i); 
    }
}

void buildMinHeap(vector<int>& arr){


    //* step down

    int n = arr.size();

    for(int i = n / 2 - 1 ; i >= 0 ; i--){

        HeapifyMin(arr , i); 
    }
}

int main() {
    
    vector<int> vec = {43,54,53,53,3,32,33,32,32,3};
    
    buildMaxHeap(vec);

    // Print Max Heap

    for(int i = 0 ; i < vec.size() ; i++){

        cout << vec[i] << " ";
    }

    cout << endl;

    buildMinHeap(vec);

    // Print Min Heap

    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << " ";
    }

    cout << endl;
    
    return 0;
}