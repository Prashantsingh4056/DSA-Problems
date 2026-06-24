#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &heap, int val)
{

    int index = heap.size();

    // first insert the element to last empty position
    heap.push_back(val);

    // now move it to the correct place

    // parent index for index i =>  ((i - 1) / 2)
    while (index > 0 && heap[(index - 1) / 2] < heap[index])
    {

        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}


void Heapify(vector<int>& heap , int index){

    int n = heap.size();
    int largest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && heap[left] > heap[largest]) largest = left;

    if(right < n && heap[right] > heap[largest]) largest = right;

    if(index != largest){

        swap(heap[largest] , heap[index]);
        Heapify(heap , largest);
    }
}

void Delete(vector<int>& heap){

    int n = heap.size();

    heap[0] = heap[n - 1];

    heap.pop_back();

    Heapify(heap , 0);
}

int main()
{

    vector<int> heap;

    insert(heap, 12);
    insert(heap, 122);
    insert(heap, 132);
    insert(heap, 46);
    insert(heap, 36);

    // Printing the Max Heap
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }

    cout << endl;

    Delete(heap);

    // Printing the Max Heap after deletion
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }

    cout << endl;

    return 0;
}