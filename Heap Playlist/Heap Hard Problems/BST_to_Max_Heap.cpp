#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    // Store BST elements
    // Inorder of BST is sorted
    void findInorder(Node* root,
                     vector<int>& inorder){

        if(!root)
            return;

        findInorder(root->left,inorder);

        inorder.push_back(root->data);

        findInorder(root->right,inorder);
    }

    // Fill tree using Postorder
    void convertToMaxHeap(int& index,
                          vector<int>& inorder,
                          Node* root){

        if(!root)
            return;

        // Fill left subtree
        convertToMaxHeap(index,
                         inorder,
                         root->left);

        // Fill right subtree
        convertToMaxHeap(index,
                         inorder,
                         root->right);

        // Parent gets larger value later
        root->data = inorder[index++];
    }

    void convertToMaxHeapUtil(Node* root) {

        // Step 1
        // Store sorted elements
        vector<int> inorder;

        findInorder(root,inorder);

        // Step 2
        // Fill tree in Postorder
        int index = 0;

        convertToMaxHeap(index,
                         inorder,
                         root);
    }
};


