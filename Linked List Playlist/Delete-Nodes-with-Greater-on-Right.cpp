#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

//+ Approach 1  : With Stack

Node *compute(Node *head)
{

    // here we use the Stack Data Structure

    stack<Node *> stk;
    Node *L1 = head;

    Node *dummyNode = new Node(-1);

    while (L1 != NULL)
    {

        while (!stk.empty() && stk.top()->data < L1->data)
        {
            stk.pop();
        }

        stk.push(L1);

        L1 = L1->next;
    }

    head = NULL;

    while (!stk.empty())
    {

        Node *curr = stk.top();
        stk.pop();

        curr->next = head;
        head = curr;
    }

    return head;
}

//+ Approach 2 : Without Stack by reversing the LL

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *compute2(Node *head)
{
    if (!head || !head->next)
        return head;

    // 1. Reverse the list
    head = reverseList(head);

    // 2. Filter nodes from left to right (originally right to left)
    Node *curr = head;
    int max_val = curr->data;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next->data < max_val)
        {
            // Skip the next node and free memory
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            // Update max and move forward
            curr = curr->next;
            max_val = curr->data;
        }
    }

    // 3. Reverse back to restore original direction
    return reverseList(head);
}

int main()
{

    //! 12->15->10->11->5->6->2->3

    Node *root = new Node(12);
    root->next = new Node(15);
    root->next->next = new Node(10);
    root->next->next->next = new Node(11);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = new Node(2);
    root->next->next->next->next->next->next->next = new Node(3);

    Node *head = compute2(root);

    while (head != NULL)
    {

        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}