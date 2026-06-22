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


//+ Preorder Inorder Postorder in one traversal

vector<vector<int>> preorderInorderPostorderInOneCode(Node* root){

    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;

    stack< pair<Node* , int> > st;
    
    st.push({root , 1});

    while(!st.empty()){

        auto it = st.top();
        st.pop();

        //* Preorder
        if(it.second == 1){

            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            //& push to the stack if its Left exists
            if(it.first->left){
                st.push({it.first->left , 1});
            }
        }

        else if(it.second == 2){
            
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            //& push to the stack if its Right exists
            if(it.first->right){
                st.push({it.first->right , 1});
            }

        }

        else {

            postOrder.push_back(it.first->data);
        }
    }

    return {preOrder , inOrder , postOrder};
}

int main() {


    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> preOrder = preorderInorderPostorderInOneCode(root)[0];
    vector<int> inOrder = preorderInorderPostorderInOneCode(root)[1];
    vector<int> postOrder = preorderInorderPostorderInOneCode(root)[2];

    cout << "Preorder Traversal : " << endl;
    for(auto it : preOrder){
        cout << it << " ";
    }

    cout << endl;
    
    cout << "inorder Traversal : " << endl;
    for(auto it : inOrder){
        cout << it << " ";
    }

    cout << endl;

    cout << "postorder Traversal : " << endl;
    for(auto it : postOrder){
        cout << it << " ";
    }

    cout << endl;
    
    return 0;
}


//TODO Explanation :

//todo :  https://www.geeksforgeeks.org/dsa/preorder-postorder-and-inorder-traversal-of-a-binary-tree-using-a-single-stack/

//* Approach

//^ We use a stack to simulate the recursive traversal process. For every node, we maintain a state that indicates which part of the traversal is currently being performed.

//& State 1 → Node is visited for the first time (Preorder).
//& State 2 → Left subtree has been processed (Inorder).
//& State 3 → Both left and right subtrees have been processed (Postorder).

//! Steps
//* Create three vectors to store the preorder, inorder, and postorder traversals.
//* Create a stack that stores pairs of (node, state).
//* Push the root node into the stack with state 1.
//* While the stack is not empty:
//* Pop the top element (node, state).
//* If the state is 1:
//* Add the node's value to the preorder traversal.
//* Increment its state to 2 and push it back into the stack.
//* Push its left child (if it exists) with state 1.
//* If the state is 2:
//* Add the node's value to the inorder traversal.
//* Increment its state to 3 and push it back into the stack.
//* Push its right child (if it exists) with state 1.
//* If the state is 3:
//* Add the node's value to the postorder traversal.
//* Do not push the node back, as it has been completely processed.
//* Continue this process until the stack becomes empty.
//* Return the three traversal arrays.
//* Intuition

//* Each node is processed three times:

//& 1st visit → Preorder
//& 2nd visit → Inorder
//& 3rd visit → Postorder

//& Thus, a single traversal of the tree generates all three traversals simultaneously.

//+ Complexity
//+ Time Complexity: O(N)
//+ Each node is processed exactly three times (constant work per node).
//+ Space Complexity: O(N)
//+ Stack can hold up to O(N) nodes in the worst case (skewed tree).