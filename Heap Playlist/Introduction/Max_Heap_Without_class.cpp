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

void Delete(vector<int>& heap){

    
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
        cout << heap[i] << endl;
    }

    cout << endl;

    return 0;
}