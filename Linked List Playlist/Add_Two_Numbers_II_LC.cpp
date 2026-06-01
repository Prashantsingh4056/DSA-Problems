#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//+  Approach 1 -> Reversing LL 

ListNode *reverseLL(ListNode *head)
{
    ListNode *prevNode = nullptr;
    ListNode *nextNode = nullptr;
    ListNode *currNode = head;

    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}

ListNode *addTwoNumbersII(ListNode *l1, ListNode *l2)
{
    ListNode *revL1Head = reverseLL(l1);
    ListNode *revL2Head = reverseLL(l2);

    ListNode *resultHead = nullptr;
    int carry = 0;

    while (revL1Head != nullptr || revL2Head != nullptr || carry != 0)
    {
        int sum = 0;
        if (revL1Head)
        {
            sum += revL1Head->val;
        }

        if (revL2Head)
        {
            sum += revL2Head->val;
        }

        sum += carry;

        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;

        newNode->next = resultHead;
        resultHead = newNode;

        if (revL1Head)
            revL1Head = revL1Head->next;
        if (revL2Head)
            revL2Head = revL2Head->next;
    }

    return resultHead;
}

//+  Approach 2 -> Stack based



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
    ListNode *tempResult = addTwoNumbersII(l1, l2);
    while (tempResult != nullptr)
    {
        cout << tempResult->val << (tempResult->next ? " -> " : "");
        tempResult = tempResult->next;
    }
    cout << endl;

    return 0;
}
