#include <iostream>
using namespace std;

/*
Sum Lists: You have two numbers represented by a linked list, where each ListNodecontains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .Thatis,617 + 295.
Output: 2 - > 1 - > 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
Output: 9 - > 1 - > 2. That is, 912. 

First Approach:
We can iterate through both lists and just add the numbers. 
We will have to have a boolean that keeps track of whether or not there is a carry from one step to the other
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head_ptr) {

  while (head_ptr != nullptr) {
    cout << head_ptr->val << "\t";
    head_ptr = head_ptr->next;
  }

  cout << "\n";
}

void addRest(ListNode* result, ListNode* listToAdd) {
  while (listToAdd) {
    result->next = listToAdd;
    result = result->next;
  }
}

ListNode* sumListsReverse(ListNode* l1, ListNode* l2) {

  ListNode* result = nullptr;
  ListNode* result_head = nullptr;

  while (l1 && l2) {
    cout << l1->val << "\t" << l2->val << "\n";
    l1 = l1->next;
    l2 = l2->next;
  }

  return result_head;
}

int main() {

  int arr[3] = {3, 6, 4};

  ListNode* head1 = new ListNode(arr[0]);
  ListNode* trav = head1;

  for (int i = 1; i < 3; ++i) {
    ListNode* temp = new ListNode(arr[i]);
    trav->next = temp;
    trav = trav->next;
  }

  ListNode* head2 = new ListNode(arr[2]);
  trav = head2;

  for (int i = 1; i >= 0; --i) {
    trav->next = new ListNode(arr[i]);
    trav = trav->next;
  }

  printList(head1);
  printList(head2);

  ListNode* result = sumListsReverse(head1, head2);

  return 0;
}