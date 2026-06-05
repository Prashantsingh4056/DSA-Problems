#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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

//+ BFS Traversal in C++

//* Level Order Traversal : Traverse the tree level by level from left to right

void levelOrder(Node* root){

    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int levelSize = q.size();
        vector<int> currLevel;

        for(int i = 0 ; i < levelSize ; i++){

            Node* curr = q.front();
            q.pop();

            currLevel.push_back(curr->data);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

        }

        // Print the current level
        for(int val : currLevel){
            cout << val << " ";
        }
        cout << endl; // Move to the next line after printing each level
    }
}

int main(){
    
    
    // initializing the tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left = new Node(7);

    // Tree looks like :
    //        1
    //       / \   
    //      2   3
    //     / \  / \
    //    7  4 5   6

    // Calling the level order traversal function
    cout << "Level Order Traversal: " << endl;
    levelOrder(root);
    
    return 0;
}