#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


//+ DFS Traversals in C++

//* Inorder Traversal : Left -> Root -> Right

void inorder(Node* root){

    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//* Preorder Traversal : Root -> Left -> Right

void preorder(Node* root){
    if(!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//* Postorder Traversal : Left -> Right -> Root

void postorder(Node* root){
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int main() {
    
    // initializing the tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);  
    
    
    // Tree looks like :
    //         1
    //        / \
    //       2   3
    //        \
    //         4

    cout << "Inorder Traversal : ";
    inorder(root);  

    cout << "\nPreorder Traversal : ";
    preorder(root);


    cout << "\nPostorder Traversal : ";
    postorder(root);
    
    return 0;
}