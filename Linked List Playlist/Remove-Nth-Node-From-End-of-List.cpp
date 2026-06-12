#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    // if the root is NULL or root->next is NULL , return NULL
    if (head == NULL || head->next == NULL)
        return NULL;

    // initialize a pointer at head
    ListNode *fast = head;

    // Move fast pointer n times
    while (n--)
    {
        fast = fast->next;
    }

    // if fast == NULL after n steps , this means n is equal to size of Linked list , in that case , delete the starting node and return the head's next node
    if (fast == NULL)
    {

        ListNode *delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }

    // if not , initialize a slow pointer at head , move them one by one , 
    // if fast  reaches last node , slow pointer will move to a node before the 
    // Nth node from last , delete the slow's next node and return head

    ListNode *slow = head;
    while (fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next;
    }

    ListNode *deleteNode = slow->next;

    slow->next = slow->next->next;
    delete deleteNode;

    return head;
}

int main()
{
    
    

    return 0;
}