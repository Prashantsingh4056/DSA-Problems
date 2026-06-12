#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//+ Iterative Way

ListNode* reverseList(ListNode* head) {
        
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* nextNode = NULL;

        // Just change links of curr and prev 
        while(currNode != NULL){

            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }


//+ recursive Way  (Implement it)

ListNode* reverseLL(ListNode* head) {
    // Base case: if list is empty or has only one node, it's already reversed
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Step 1: Recursively reverse the rest of the list
    ListNode* newHead = reverseLL(head->next);

    // Step 2: Make the next node point back to the current node
    head->next->next = head;

    // Step 3: Break the old forward link to prevent a cycle
    head->next = nullptr;

    // Step 4: Return the new head of the reversed list
    return newHead;
}

int main() {
    
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode* headOfRevLL = reverseList(l1);

    while (headOfRevLL != nullptr)
    {
        cout << headOfRevLL->val << (headOfRevLL->next ? " -> " : "");
        headOfRevLL = headOfRevLL->next;
    }
    cout << endl;
    
    
    return 0;
}