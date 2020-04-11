#include <iostream>
using namespace std;

/*
Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

Edge Cases: What should happen if K is larger than the length of the linked list? Let's assume for our purposes that we should just return a nullptr.
However an equally valid hting to do is to throw an exception.

Approach: Iterative

First iterate a fast ptr K spots forward in the list.
Then iterate a slow ptr (which starts at the head) along with the fast ptr.
By the time the fast ptr reaches the last element, the slow ptr will be pointing to the kth last element.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* kthLast(ListNode* head_ptr, int k) {

  ListNode* fast_ptr = head_ptr;
  ListNode* slow_ptr = head_ptr;

  for (int i = 1; i < k; ++i) {
    if (fast_ptr == nullptr) {
      return nullptr;
    }
    fast_ptr = fast_ptr->next;
  }

  while (fast_ptr->next != nullptr) {
    fast_ptr = fast_ptr->next;
    slow_ptr = slow_ptr->next;
  }

  cout << slow_ptr->val;
  return slow_ptr;
}

int main() {

  int arr[7] = {1, 2, 3, 4, 5, 6, 7};

  ListNode* head_ptr = new ListNode(arr[0]);
  ListNode* trav_ptr = head_ptr;

  for (int i = 1; i < 7; ++i) {
    trav_ptr->next = new ListNode(arr[i]);
    trav_ptr = trav_ptr->next;
  }

  kthLast(head_ptr, 4);

  return 0;
}