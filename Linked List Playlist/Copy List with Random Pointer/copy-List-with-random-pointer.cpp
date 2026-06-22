#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//+ Method 1: using map to store nodes and rebuilding the list ---------------------------

Node *copyRandomList(Node *head)
{

    if (head == NULL)
        return NULL;

    //  original  , copy
    map<Node *, Node *> mpp;

    Node *temp = head;

    while (temp != NULL)
    {

        int currNodeVal = temp->val;

        Node *newNode = new Node(currNodeVal);

        // store in map
        mpp[temp] = newNode;

        temp = temp->next;
    }

    // build the copy List

    temp = head;
    while (temp != NULL)
    {

        mpp[temp]->next = mpp[temp->next];

        mpp[temp]->random = mpp[temp->random];

        temp = temp->next;
    }

    return mpp[head];
}

//+ Method 2: without using map ------------------------------------------------------------

//* T.C. = O(3N)
//* S.C. = O(N) -> to create the list

Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;

    // Step 1: Insert copy nodes in between

    Node *temp = head;

    while (temp != NULL)
    {
        Node *nextNode = temp->next;

        // create new copy node
        Node *copyNode = new Node(temp->val);

        // point copy node to temp next
        copyNode->next = nextNode;

        // point temp next to copy bode
        temp->next = copyNode;

        // move temp to next
        temp = nextNode;
    }

    // Step 2: Connect random pointers

    temp = head;

    while (temp != NULL)
    {

        Node *copyNode = temp->next;

        if (temp->random == NULL)
        {
            copyNode->random = NULL;
        }
        else
        {
            copyNode->random = temp->random->next;
        }

        temp = temp->next->next;
    }

    // step 3: Connect next pointer

    Node *dummyNode = new Node(-1);

    Node *res = dummyNode;

    temp = head;

    while (temp != NULL)
    {
        Node *copyNode = temp->next;

        res->next = copyNode;

        res = res->next;

        temp->next = copyNode->next;

        temp = temp->next;
    }

    return dummyNode->next;
}


//&  Step 1: Interweaving the Copy Nodes
//* This step inserts a duplicate node immediately after every original node. [1] 
//* Before Step 1:

//! Original:   [ A ] -------> [ B ] -------> NULL

//* During the Step 1 loop:

//*    1. We look at node A. We create its clone A'.
//*    2. We point A' to A->next (which is B).
//*    3. We point A->next to A'.
//*    4. We repeat this for node B. [2, 3] 

//* After Step 1 completes:

//! Interwoven: [ A ] -> [ A' ] -> [ B ] -> [ B' ] -> NULL

//* The clone nodes are now perfectly locked into place right behind their originals.
//* ------------------------------
//& ## Step 2: Connecting the Random Pointers
//* Because every clone node lives exactly one step ahead of its original node, we can easily find where the clone's random pointer should point. [4] 
//* The Logic:
//* If temp is at A, then A's clone is temp->next (A').
//* If A's random pointer points to B, then B's clone must be at B->next (B').
//* Therefore, the formula is: copyNode->random = temp->random->next.

//* temp is at A.
//* temp->random is B.
//* temp->random->next is B'.
//* So, A'->random points to B'.

//* Crucial detail: We advance the loop using temp = temp->next->next. This safely jumps over the clone node to reach the next original node (B) without changing any pointers yet. [5, 6] 
//* ------------------------------
//& ## Step 3: Untangling and Separating the Lists
//* This step uses a pointer dance to simultaneously restore the original list and link the clone list together. We use a dummyNode to easily build the new list tail-first. [7, 8] 
//* Initial Setup: dummyNode -> NULL, res points to dummyNode, temp is at A.
//* ## Iteration 1 (Processing node A):

//*    1. Identify the copy node: copyNode = temp->next (A').
//*    2. Attach it to our results: res->next = A'. Move res forward to A'.
//*    3. Restore original connection: temp->next = A'->next (which links A back to B).
//*    4. Move temp forward: temp = temp->next (moves temp to B).

//! Original restored so far: [ A ] -------> [ B ] -> [ B' ] -> NULL
//! Clone list built so far:  dummy -> [ A' ]

//* ## Iteration 2 (Processing node B):

//*    1. Identify the copy node: copyNode = temp->next (B').
//*    2. Attach it to our results: res->next = B'. Move res forward to B'.
//*    3. Restore original connection: temp->next = B'->next (links B to NULL).
//*    4. Move temp forward: temp = temp->next (moves temp to NULL, ending the loop). [9, 10, 11] 

//* ------------------------------
//& ## Final State
//* The two lists are now completely independent: [12] 

//! Original: [ A ] -------> [ B ] -------> NULL
//! Clone:    [ A' ] ------> [ B' ] ------> NULL

//* Finally, we delete the temporary dummyNode and return dummyNode->next (which is A').
//* If you want, I can provide:
