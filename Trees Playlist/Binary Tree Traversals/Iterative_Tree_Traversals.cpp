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

//+ Iterative Tree Traversals in C++


//* Iterative PreOrder Traversal : Root -> Left -> Right
vector<int> iterativePreorder(Node* root){

    if(!root) return {};

    stack<Node*> st;
    st.push(root);
    vector<int> preOrder;

    while(!st.empty()){

        Node* curr = st.top();   // Take the top element of the stack
        st.pop();

        if(curr->right) st.push(curr->right);   // push the right Node first because Stack is a LIFO data structure

        if(curr->left) st.push(curr->left);

        preOrder.push_back(curr->data);
    }

    return preOrder;
}


//* Iterative Inorder Traversal : Left -> Root -> Right

vector<int> iterativeInorder(Node* root){

    if(!root) return {};

    stack<Node*> st;
    Node* curr = root;
    vector<int> inorderTraversal;

    while(true){

        if(curr){                   // Keep moving to the left until find the NULL
            st.push(curr);      // Keep the current node 

            curr = curr->left;      // move to the left until find NULL
        }

        else{

            if(st.empty()) break;

            curr = st.top();
            st.pop();

            inorderTraversal.push_back(curr->data);
            curr = curr->right;
        } 
    }

    return inorderTraversal;
}


//* Iterative Postorder Traversal :  Left -> Right -> Root

// with 2 stacks
vector<int> iterativePostorder(Node* root){

    if(!root) return {};

    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    vector<int> postorderTraversal;

    while(!st1.empty()){

        Node* curr = st1.top();
        st1.pop();

        st2.push(curr);

        if(curr->left) st1.push(curr->left);

        if(curr->right) st1.push(curr->right);
    }

    while(!st2.empty()){

        postorderTraversal.push_back(st2.top()->data);
        st2.pop();
    }

    return postorderTraversal;
}


//* Iterative Postorder Traversal :  Left -> Right -> Root

// with 1 stack

vector<int> iterativePostorder2(Node* root) {
        vector<int> postOrder;
        if (root == nullptr) return postOrder;

        stack<Node*> st;
        Node* cur = root;

        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left; // Keep moving left
            } 
            else {
                Node* temp = st.top()->right; // Check the right child
                
                // If right child is null, we can process the current root
                if (temp == nullptr) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                    
                    // Backtrack up if we just finished a right subtree
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->data);
                    }
                } 
                // If right child exists, move to it
                else {
                    cur = temp;
                }
            }
        }
        return postOrder;
    }


int main() {
    
    // initializing the tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left = new Node(7);

    //+ Tree looks like :
    //*        1
    //~       / \   
    //*      2   3
    //~     / \  / \
    //*    7  4 5   6

    
    //! Iterative Preorder Traversal
    cout << "PreOrder Traversal : " << endl;
    vector<int> preOrder = iterativePreorder(root);

    for(int i = 0 ; i < preOrder.size() ; i++){
        cout << preOrder[i] << " ";
    }

    cout << endl;

    // T.C. = O(N)
    // S.C. = O(N) ~ O(H)


    //! Iterative Inorder Traversal
    cout << "Inorder Traversal : " << endl;
    vector<int> inorder = iterativeInorder(root);

    for(int i = 0 ; i < inorder.size() ; i++){
        cout << inorder[i] << " ";
    }

    cout << endl;

    // T.C. = O(N)
    // S.C. = O(N) ~ O(H)


    //! Iterative Postorder Traversal
    cout << "Postorder Traversal : " << endl;
    vector<int> postorder = iterativePostorder(root);

    for(int i = 0 ; i < postorder.size() ; i++){
        cout << postorder[i] << " ";
    }

    cout << endl;

    // T.C. = O(N)
    // S.C. = O(2N) 

    
    


    return 0;
}