#include <bits/stdc++.h>
using namespace std;

int heightOfHeap(vector<int>& heap){

    int n = heap.size();

    if(n == 1) return 1;

    int height = floor(log2(n));

    return height;
}

int main() {
    
    vector<int> heap = {99,88,76,54,33,22,11,9,8,4,1};
    
    cout << heightOfHeap(heap) << endl;

    return 0;
}