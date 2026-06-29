#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    bool isMaxHeap(int totalNodes,
                   Node* root,
                   int index){

        // Empty tree is always valid
        if(!root)
            return true;

        // If index exceeds total nodes,
        // tree is not Complete Binary Tree
        if(index >= totalNodes)
            return false;

        // Max Heap Property
        if(root->left &&
           root->left->data > root->data)
            return false;

        if(root->right &&
           root->right->data > root->data)
            return false;

        // Check left and right subtree
        return isMaxHeap(totalNodes,
                         root->left,
                         2*index+1)

            &&

               isMaxHeap(totalNodes,
                         root->right,
                         2*index+2);
    }

    int countNodes(Node* tree){

        if(!tree)
            return 0;

        return 1
             + countNodes(tree->left)
             + countNodes(tree->right);
    }

    bool isHeap(Node* tree) {

        // Count total nodes
        int totalNodes = countNodes(tree);

        // Verify both:
        // 1. Complete Binary Tree
        // 2. Max Heap Property
        return isMaxHeap(totalNodes,
                         tree,
                         0);
    }
};


// Heap Check

// Step 1
// Count Nodes

// Step 2
// Assign array indices

// Step 3
// If index >= total nodes

// → Not CBT

// Step 4
// Check parent >= children

// If both pass

// → Heap