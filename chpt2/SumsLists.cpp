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

After multiple attempsts at this appraoch I have decided to change my actual implementation of it. Instead of looking only for when both lists are not null,
I will look when either one is not null and then I don't have to write a addRest function. Also, I will create a dummy node that holds a nonsense value and then just add
everything onto that dummy and return dummy->next;

This is a better strategy because I dont need to explicitly account for many edge cases, like having just one node in each list.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head_ptr) {

  while (head_ptr) {
    cout << head_ptr->val << "\t";
    head_ptr = head_ptr->next;
  }

  cout << "\n";
}

ListNode* sumListsReverse(ListNode* l1, ListNode* l2) {
  if (!l1) {
    return l2;
  }
  if (!l2) {
    return l1;
  }

  ListNode* dummy = new ListNode(0);
  ListNode* trav = dummy;

  int carry = 0;
  int sum = 0;

  while (l1 || l2) {
    int x = (l1) ? l1->val : 0;
    int y = (l2) ? l2->val : 0;

    sum = x + y + carry;

    trav->next = new ListNode(sum % 10);

    trav = trav->next;
    carry = sum / 10;

    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;
  }

  if (carry > 0) {
    trav->next = new ListNode(carry);
  }

  return dummy->next;
}

int main() {

  int arr[5] = {0};
  int arr2[3] = {0};

  ListNode* head1 = new ListNode(arr[0]);
  ListNode* trav = head1;

  for (int i = 1; i < 0; ++i) {
    ListNode* temp = new ListNode(arr[i]);
    trav->next = temp;
    trav = trav->next;
  }

  ListNode* head2 = new ListNode(arr2[0]);
  trav = head2;

  for (int i = 1; i < 0; ++i) {
    trav->next = new ListNode(arr2[i]);
    trav = trav->next;
  }

  printList(head1);
  printList(head2);

  ListNode* result = sumListsReverse(head1, head2);
  printList(result);

  return 0;
}