#include <iostream>
using namespace std;

/*
Delete Middle Node: Implement an algorithm to delete a node in the middle (Le., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.
EXAMPLE
Input: the node c from the linked list a - >b- >c - >d - >e- >f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f 

Approach: Iterative

Find the middle node by having a fast ptr and a slow ptr. The fast ptr moves twice as fast as the slow ptr.
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head_ptr) {

  while(head_ptr != nullptr) {
    cout << head_ptr->val << "\t";
    head_ptr = head_ptr->next;
  }
}

void deleteMiddleNode(ListNode*& head) {

  if(head == nullptr) { return; }

  if(head->next == nullptr) {
    head = nullptr;
    delete head;
    return; 
  }

  ListNode* fast = head;
  ListNode* slow = head;
  ListNode* helper = head;

  while(fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    helper = slow;
    slow = slow->next;
  }

  cout << slow->val;

  helper->next = slow->next;

  slow = nullptr;
  delete slow;
}

int main() {

  int arr[7] = {1, 2, 3, 4, 5, 6, 7};

  ListNode* head_ptr = new ListNode(arr[0]);
  ListNode* trav_ptr = head_ptr;

  for(int i = 1; i < 7; ++i) {
    ListNode* temp_ptr = new ListNode(arr[i]);
    trav_ptr->next = temp_ptr;
    trav_ptr = trav_ptr->next;
  }

  printList(head_ptr);
  cout << std::endl;
  deleteMiddleNode(head_ptr);
  printList(head_ptr);

  return 0;
}