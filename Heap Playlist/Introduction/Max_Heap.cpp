#include <bits/stdc++.h>
using namespace std;

// class based
class MaxHeap{

    int * arr;
    int size;  // total element in heap
    int total_size;  // total size of array

    public: 

    MaxHeap(int n){

        arr = new int(n);
        size = 0;
        total_size = n;
    }

    // insert into Heap
    void insert(int value){

        // if heap size is available or not
        if(size == total_size){
            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = value;
        int index = size;

        size++;

        // Compare it with its parent

        // parent index for index i =>  ((i - 1) / 2)
        while(index > 0 && arr[(index - 1) / 2] < arr[index]){

            swap(arr[index] , arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }


        cout << arr[index] << " is inserted into the Heap" << endl;

    }

    void Heapify(int index){

        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Largest will store the index of the element which is greater between parent , left child and right child

        if(left < size && arr[left] > arr[largest]) largest = left;
        if(right < size && arr[right] > arr[largest]) largest = right;

        if(largest != index){

            swap(arr[index] , arr[largest]);
            Heapify(largest);
        }
    }

    // This is a top down approach
    void Delete(){

        if(size == 0){
            cout << "Heap Underflow" << endl;
            return;
        }

        cout << arr[0] << " is deleted from the Heap" << endl;
        arr[0] = arr[size - 1];

        size--;

        if(size == 0) return;

        // to maintain Heap Property
        Heapify(0);
    }

    void print(){

        for(int i = 0 ; i < size ; i++){

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


int main() {
    
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);

    H1.print();

    H1.insert(233);
    H1.insert(12);
    H1.insert(124);

    H1.print();

    H1.Delete();

    H1.print();
    
    return 0;
}