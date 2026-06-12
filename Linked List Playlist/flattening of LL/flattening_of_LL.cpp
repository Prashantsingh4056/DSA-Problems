#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
  public:
  
    // Helper function to merge two sorted vertical linked lists
    Node* merge(Node* l1 , Node* l2){
        
        // Create a temporary dummy node to easily build the merged list
        Node* dummyNode = new Node(-1);
        Node* currNode = dummyNode;
        
        // Traverse both lists until one runs out
        while(l1 != NULL && l2 != NULL){
            
            // Attach the smaller node to the bottom pointer
            if(l1->data <= l2->data){
                currNode->bottom = l1;
                currNode = currNode->bottom; // Move current pointer forward
                l1 = l1->bottom;             // Move l1 list pointer forward
            } else {
                currNode->bottom = l2;
                currNode = currNode->bottom; // Move current pointer forward
                l2 = l2->bottom;             // Move l2 list pointer forward
            }
            
            // Disconnect the horizontal 'next' pointer as we only need the 'bottom' structure
            currNode->next = NULL;
        }
        
        // Attach any remaining nodes from l1 or l2
        if(l1) currNode->bottom = l1;
        else currNode->bottom = l2;
        
        // Return the actual head of the merged list (skipping the dummy node)
        return dummyNode->bottom;
    }
  
    // Main function to flatten the multi-level linked list
    Node *flatten(Node *root) {
        
        // Base Case: If the list is empty or has only one vertical list left
        if(root == NULL || root->next == NULL) return root;
        
        // Recursively move to the end of the horizontal 'next' chain
        Node* mergedNode = flatten(root->next);
        
        // Merge the current vertical list with the already flattened/merged right side
        return merge(root , mergedNode);
    }
};

int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    return 0;
}