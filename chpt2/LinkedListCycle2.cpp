/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


FOLLOW UP: Can you do it without using extra space?

First Approach: Using a hash table

I can loop through the list and insert the pointers into the hashmap. Once I come accross something that already exists in the hashmap, I have found the cycle.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getCycleWithExtraSpace(ListNode* head) {

  unordered_map<ListNode*, bool> map;

  while (head) {

    if (map[head]) {
      return head;
    }

    map[head] = true;
    head = head->next;
  }

  return nullptr;
}

/*
The solution using extra space is pretty rudimenatary. The real challenge comes from the follow up question where we need to not use any extra space.
*/

int main() {

  int arr[7] = {1, 2, 3, 3, 4, 4, 5};

  ListNode* head_ptr = new ListNode(arr[0]);
  ListNode* trav_ptr = head_ptr;

  for (int i = 1; i < 7; ++i) {
    ListNode* temp_ptr = new ListNode(arr[i]);
    trav_ptr->next = temp_ptr;
    trav_ptr = trav_ptr->next;
  }

  return 0;
}