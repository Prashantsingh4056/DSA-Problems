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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    int carry = 0;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1 != NULL)
        {
            sum += t1->val;
        }
        if (t2 != NULL)
        {
            sum += t2->val;
        }

        ListNode *newNode = new ListNode(sum % 10);

        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }

    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        curr->next = newNode;
    }

    return dummyNode->next;
}

int main()
{
    // --- DIRECTLY CREATING LIST 1: 7 -> 2 -> 4 -> 3 ---
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    // --- DIRECTLY CREATING LIST 1: 2 -> 4 -> 6 -> 5 ---
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    l2->next->next->next = new ListNode(5);

    // --- PRINT RESULT ---
    // Result: 9 -> 7 -> 0 -> 8
    cout << "Result: ";
    ListNode *tempResult = addTwoNumbers(l1, l2);
    while (tempResult != nullptr)
    {
        cout << tempResult->val << (tempResult->next ? " -> " : "");
        tempResult = tempResult->next;
    }
    cout << endl;

    return 0;
}
