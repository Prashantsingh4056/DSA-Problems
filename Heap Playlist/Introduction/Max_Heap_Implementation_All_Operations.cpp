class maxHeap {
  private:
    // Initialize your data members
    
    vector<int> heap;
    
    void Heapify(int index){
        
        // top down approach
        
        int n = heap.size();
        int largest = index;
        
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        
        if(leftChild < n && heap[leftChild] > heap[largest]) largest = leftChild;
        
        if(rightChild < n && heap[rightChild] > heap[largest]) largest = rightChild;
        
        if(largest != index){
            
            swap(heap[largest] , heap[index]);
            Heapify(largest);
        }
    }

  public:

    void push(int x) {
        // Insert x into the heap
        int index = heap.size();
        
        heap.push_back(x);
        
        while(index > 0 && heap[(index - 1) / 2] < heap[index]){
            
            swap(heap[index] , heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void pop() {
        
        if(!heap.size()) return;
        
        int lastIdx = heap.size() - 1;
        
        heap[0] = heap[lastIdx];
        
        heap.pop_back();
        
        Heapify(0);
    }

    int peek() {
        // Return the top element or -1 if empty
        
        if(heap.empty()) return -1;
        
        return heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        
        return heap.size();
    }
};