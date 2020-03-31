#include<iostream>
#include <unordered_map>
using namespace std;

/*
Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
What if the list was sorted?

Edge Cases:

Quick refresher: In order to remove an elem from a singly liunked list, we must have a pointer to the element directly before the element we want to delete.
This way we can still reconnect the list after the deletion.

First Approach: Hashmap

I would loop through the entire linked list and populate a hashmap to record distinct values.
If i come across a value in the list that already exists in the hashmap, I will remove the 
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

void removeDups(ListNode*& head_ptr) {

  unordered_map<int, bool> map;

  if(head_ptr == nullptr) { return; }
  map[head_ptr->val] = true;

  ListNode* slow_ptr = head_ptr;
  ListNode* fast_ptr = head_ptr->next ;

  while(fast_ptr != nullptr) {
    if(map[fast_ptr->val]) {
      slow_ptr->next = fast_ptr->next;
      fast_ptr = nullptr;
      delete fast_ptr;

      fast_ptr = slow_ptr->next;
      
    } else {
      map[fast_ptr->val] = true;

      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
    }
  }

  printList(head_ptr);
}

ListNode* removeDupsSorted(ListNode* head_ptr) {
  if(head_ptr == nullptr) { return nullptr; }

  ListNode* slow_ptr = head_ptr;
  ListNode* fast_ptr = head_ptr->next ;

  while(fast_ptr != nullptr) {
    if(slow_ptr->val == fast_ptr->val) {
      slow_ptr->next = fast_ptr->next;
      fast_ptr = nullptr;
      delete fast_ptr;

      fast_ptr = slow_ptr->next;
      
    } else {

      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
    }
  }

  printList(head_ptr);

  return head_ptr;
}

int main() {

  int arr[7] = {1, 2, 3, 3, 4, 4, 5};

  ListNode* head_ptr = new ListNode(arr[0]);
  ListNode* trav_ptr = head_ptr;

  for(int i = 1; i < 7; ++i) {
    ListNode* temp_ptr = new ListNode(arr[i]);
    trav_ptr->next = temp_ptr;
    trav_ptr = trav_ptr->next;
  }

  removeDupsSorted(head_ptr);

  return 0;
}