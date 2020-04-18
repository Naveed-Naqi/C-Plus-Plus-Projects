#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given a linked list return whether or not is has a cycle.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {

  unordered_map<ListNode*, bool> map;

  while (head) {

    if (map[head]) {
      return true;
    }

    map[head] = true;
    head = head->next;
  }

  return false;
}

int main() {

  int arr[7] = {1, 2, 3, 3, 4, 4, 5};

  ListNode* head_ptr = new ListNode(arr[0]);
  ListNode* trav_ptr = head_ptr;

  for (int i = 1; i < 7; ++i) {
    ListNode* temp_ptr = new ListNode(arr[i]);
    trav_ptr->next = temp_ptr;
    trav_ptr = trav_ptr->next;
  }

  hasCycle(head_ptr);

  return 0;
}