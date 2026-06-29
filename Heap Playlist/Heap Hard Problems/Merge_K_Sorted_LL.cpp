#include <bits/stdc++.h>
using namespace std;

//+ Problem Statement : 
//w You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

//w Merge all the linked-lists into one sorted linked-list and return it.

//* _____________________________________ Approach : 1 _____________________________________

//^ put all  nodes to a priority queue (min heap)
//^ then pop the elements to construct the final sorted list 

//! T.C. => O(NK log(NK))
//! S.C. => O(NK)

//* ______________________________________ Approach : 2 _____________________________________

//todo  This Approach is similar to approach 3 of Kth Element in a Matrix

//? Procedure :

//w  arr => _________________________
//w         |   |   |   |   |   |   |
//w         ‾‾|‾‾‾|‾‾‾|‾‾‾|‾‾‾|‾‾‾|‾‾
//w           4   3   2   5   1   6
//w           |   |   |   |       |
//w           7   10  8   9       12
//w           |       |
//w           11      13


//^ at first , push all the starting k nodes to Priority queue , pq => { 4 3 2 5 1 6}
//^ then pop the top element (1) , then push 1 next node , pq => { 4 3 2 5 6}
//^ pop the smallest (2) , then push (8) , pq => { 4 3 5 6 8}
//^ pop 3 , push 10 , pq => { 4 10 8 5 6}
//^ pop 4 , push 7 , pq => { 7 10 8 5 6}
//^ pop 5 , push 9 , pq => { 7 10 8 9 6}
//^ pop 6 , push 12 , pq => { 7 10 8 9 12}
//^ pop 7 , push 11 , pq => {11 10 8 9 12}
//^ pop 8 , push 13 , pq => {11 10 13 9 12}
//^ pop 9 , pq => {11 10 13 12}
//^ pop 10 , pq => {11 13 12}
//^ pop 11 , pq => {12 13}
//^ pop 12 , pq => {13}
//^ pop 13 , pq => {}

//+ final answer : 1 2 3 4 5 6 7 8 9 10 11 12 13

//~ Here we need to use customized heap

//? in case of Heap , comparator function works opposite

//+ priority_queue<Node* , vector<Node*> , compare> pq

//+  Nodes => a , b
//+ Min Heap: a->data  >  b->data
//+ Max Heap: a->data  <  b->data


//w _________________________________________ Code : _______________________________________


class Solution {
public:

    // Custom comparator structure to build a Min-Heap
    struct compare {

        // The priority_queue requires a strict weak ordering.
        // Returning (a->val > b->val) ensures the SMALLEST value stays at the top.

        bool operator()(const ListNode* a , const ListNode* b) {

            // Safe to access ->val directly here because we pre-filter out NULLs
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Corner case: If the input vector is empty, return NULL immediately
        if (lists.size() == 0) return NULL;

        // Min-Heap declaration: stores node pointers ordered by our custom comparator
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        //! Step 1: Push the starting node (head) of every non-empty list into the heap
        for (ListNode* head : lists) {
            if (head != nullptr) { // Crucial check: prevents NULLs from breaking the heap
                pq.push(head);
            }
        }

        //! Step 2: Set up a dummy node to easily construct the merged result list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode; // This pointer tracks the tail of our new merged list

        //! Step 3: Process nodes one by one until the heap is empty
        while (!pq.empty()) {

            // Extract the node with the absolute smallest value currently in the heap
            ListNode* temp = pq.top();
            pq.pop();

            // Safety guard (redundant if initialization was clean, but safe)
            if (temp == NULL) continue;

            // Link this smallest node to our growing merged list
            curr->next = temp;
            curr = curr->next; // Advance our tail pointer

            //! Step 4: If the extracted node has a next element, push it into the heap
            // This maintains exactly one candidate from each list inside the heap
            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        // Save the head of the merged list (skipping the dummy node)
        ListNode* result = dummyNode->next;
        
        // Clean up memory allocated for the dummy node to prevent memory leaks
        delete dummyNode; 

        return result;
    }
};
