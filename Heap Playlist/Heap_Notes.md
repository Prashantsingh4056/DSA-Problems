These are the kind of notes I would keep for interviews and revision. Since you're learning DSA for placements, focus on **intuition + what each line is doing**, not just memorizing code.

# Heaps Notes

## 1. What is a Heap?

A Heap is a **Complete Binary Tree** that follows a special property.

### Max Heap

Every parent is greater than or equal to its children.

```text
        100
       /   \
      50    80
     / \   /
    20 30 40
```

### Min Heap

Every parent is smaller than or equal to its children.

```text
        10
       /  \
      20   30
     / \
    40 50
```

---

## Why store Heap in Array?

Because a Complete Binary Tree has no gaps.

For **0-Based Indexing**:

```text
Parent = (i - 1) / 2

Left Child = 2*i + 1

Right Child = 2*i + 2
```

Example:

```text
        132
       /   \
     122    12
     /
    46
```

Stored as:

```cpp
[132,122,12,46]
```

---

# INSERT OPERATION (Building Heap One By One)

Your code:

```cpp
void insert(vector<int> &heap, int val)
```

---

## Step 1: Find Position

```cpp
int index = heap.size();
```

Suppose:

```cpp
heap = [132,122,12,46]
```

Size = 4

New element will go at index 4.

---

## Step 2: Insert at End

```cpp
heap.push_back(val);
```

Insert 200

```text
Before

132
/ \
122 12
/
46

After inserting at end

132
/ \
122 12
/ \
46 200
```

Array:

```cpp
[132,122,12,46,200]
```

Heap property may be violated.

---

## Step 3: Compare with Parent

```cpp
while(index > 0 &&
      heap[(index-1)/2] < heap[index])
```

Current:

```cpp
index = 4
```

Parent:

```cpp
(4-1)/2 = 1
```

```text
Parent = 122
Child = 200
```

Since

```cpp
122 < 200
```

swap.

---

## Step 4: Swap

```cpp
swap(heap[(index-1)/2], heap[index]);
```

Array:

```cpp
[132,200,12,46,122]
```

---

## Step 5: Move Up

```cpp
index = (index-1)/2;
```

Now

```cpp
index = 1
```

Compare again.

Parent:

```cpp
(1-1)/2 = 0
```

```text
132 < 200
```

Swap.

Array:

```cpp
[200,132,12,46,122]
```

---

## Final Heap

```text
        200
       /   \
     132    12
    /  \
   46  122
```

This process is called:

### Up Heapify / Bubble Up / Percolate Up

---

## Complexity

Height of heap:

```text
log N
```

Worst case element goes from leaf to root.

```cpp
Time = O(logN)
Space = O(1)
```

---

# HEAPIFY FUNCTION

Your code:

```cpp
void Heapify(vector<int>& heap , int index)
```

Purpose:

Restore Max Heap property when a node becomes invalid.

---

## Example

Array:

```cpp
[12,122,132,46,36]
```

Tree:

```text
       12
      /  \
    122 132
    / \
   46 36
```

12 should not be at root.

---

## Step 1

```cpp
int largest = index;
```

Assume:

```cpp
index = 0
largest = 0
```

---

## Step 2

Find children

```cpp
left = 2*index + 1
right = 2*index + 2
```

For root:

```cpp
left = 1
right = 2
```

---

## Step 3

Compare Left Child

```cpp
if(left<n &&
   heap[left] > heap[largest])
```

```text
122 > 12
```

So

```cpp
largest = 1
```

---

## Step 4

Compare Right Child

```cpp
132 > 122
```

So

```cpp
largest = 2
```

---

## Step 5

Swap

```cpp
swap(heap[largest], heap[index]);
```

Array:

```cpp
[132,122,12,46,36]
```

---

## Step 6

Recursive Call

```cpp
Heapify(heap, largest);
```

Now fix subtree rooted at index 2.

---

### Key Idea

Heapify assumes:

```text
Children are already heaps.
Only current node may be wrong.
```

This is why Build Heap works.

---

## Complexity

Height traversed:

```cpp
O(logN)
```

Space:

```cpp
O(logN)
```

(recursion stack)

---

# DELETE OPERATION

Your code:

```cpp
void Delete(vector<int>& heap)
```

---

## Initial Heap

```cpp
[132,122,12,46,36]
```

```text
        132
       /   \
     122   12
    / \
   46 36
```

---

## Step 1

Replace root with last element

```cpp
heap[0] = heap[n-1];
```

```cpp
[36,122,12,46,36]
```

---

## Step 2

Delete last node

```cpp
heap.pop_back();
```

```cpp
[36,122,12,46]
```

Tree:

```text
       36
      / \
    122 12
    /
   46
```

---

## Step 3

Heapify Root

```cpp
Heapify(heap,0);
```

Compare:

```text
36
122
12
```

Largest:

```text
122
```

Swap.

```cpp
[122,36,12,46]
```

---

Again Heapify index 1

```text
36
46
```

Swap.

```cpp
[122,46,12,36]
```

---

## Final Heap

```text
       122
      / \
    46  12
   /
  36
```

---

## Complexity

```cpp
O(logN)
```

---

# BUILD HEAP FROM ARRAY

Your code:

```cpp
buildMaxHeap(arr)
```

---

## Important Observation

All nodes after:

```cpp
n/2 - 1
```

are leaf nodes.

Example:

```cpp
Index : 0 1 2 3 4 5 6

Nodes 3,4,5,6
```

are leaves.

Leaves are already heaps.

---

## Why Start From n/2 -1 ?

Because it is the last non-leaf node.

```cpp
for(int i=n/2-1;i>=0;i--)
```

We fix nodes from bottom to top.

---

## Example

```cpp
[43,54,53,53,3,32,33]
```

Start:

```cpp
i = n/2 -1
```

Heapify each node.

By the time we reach root:

```text
Every subtree is already a heap
```

So root can be fixed correctly.

---

## Complexity

Many students think:

```cpp
N nodes × logN
```

so

```cpp
O(NlogN)
```

Wrong.

Actual complexity:

```cpp
O(N)
```

Reason:

Most nodes are near bottom and require very little work.

---

# BUILD MIN HEAP

Same logic.

Only change:

```cpp
largest
```

becomes

```cpp
smallest
```

Comparisons reverse.

```cpp
>
```

becomes

```cpp
<
```

---

# HEAP SORT

## Idea

1. Build Max Heap.
2. Largest element reaches root.
3. Put largest element at end.
4. Restore heap.
5. Repeat.

---

## Step 1

Array:

```cpp
[33,45,2,52]
```

Build Max Heap:

```cpp
[52,45,2,33]
```

---

## Step 2

Swap root and last.

```cpp
swap(arr[0],arr[3]);
```

```cpp
[33,45,2,52]
```

52 is fixed forever.

---

## Step 3

Heapify remaining heap.

Size becomes:

```cpp
3
```

Heapify:

```cpp
[45,33,2,52]
```

---

## Step 4

Repeat

```cpp
swap(arr[0],arr[2])
```

```cpp
[2,33,45,52]
```

Heapify size 2

```cpp
[33,2,45,52]
```

Repeat.

Final:

```cpp
[2,33,45,52]
```

---

## Why does Heap Sort give Ascending Order?

Because every iteration places the current maximum at the end.

```text
Largest → Last
2nd Largest → Second Last
3rd Largest → Third Last
```

Eventually:

```text
Ascending Order
```

---

## Complexity

Build Heap:

```cpp
O(N)
```

For each element:

```cpp
Heapify => O(logN)
```

Repeated N times:

```cpp
O(NlogN)
```

Total:

```cpp
O(NlogN)
```

Space:

```cpp
O(logN)
```

(recursive version)

```cpp
O(1)
```

(iterative Heapify)

---

# PRIORITY QUEUE

A Priority Queue is simply a heap implementation provided by STL.

---

## Max Heap

```cpp
priority_queue<int> pq;
```

Highest element stays at top.

```cpp
pq.top();
```

returns maximum element.

---

## Min Heap

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Smallest element stays at top.

---

## Operations

### Insert

```cpp
pq.push(x);
```

Time:

```cpp
O(logN)
```

---

### Top

```cpp
pq.top();
```

Time:

```cpp
O(1)
```

---

### Delete

```cpp
pq.pop();
```

Time:

```cpp
O(logN)
```

---

# Interview Questions

### Difference between Heap and BST?

| Heap                 | BST              |
| -------------------- | ---------------- |
| Parent relation only | Full ordering    |
| Fast max/min         | Fast searching   |
| Search = O(N)        | Search = O(logN) |

---

### Why use Heap?

When you frequently need:

```text
Maximum element
Minimum element
Kth largest
Kth smallest
Priority scheduling
Top K problems
```

---

### Most Important Formulae

```cpp
Parent = (i-1)/2

Left = 2*i+1

Right = 2*i+2
```
 
---
---


