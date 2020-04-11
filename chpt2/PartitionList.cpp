#include <iostream>
using namespace std;

/*
Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.
EXAMPLE
Input: 3 -) 5 -) 8 -) 5 -) 113 -) 2 -) 1 [partition = 5]
Output: 3 -) 1 -) 2 -) 113 -) 5 -) 5 -) 8 

Potential Question: Does it need to be stable? Let's assume for this first approach that it does not need to be stable

First Approach: Unstable

We create two lists, a left and right. The left contains all values less than the partition and the right contains all  values greater than or equal to the partition.
We populate both lists as we go and then connect the both of them at the end. Because we do not need this list to be stable, everytime we add elements to the right
we can just add them to the front of the right list. This way, we don't need to use a fourth pointer to keep track of the front of the right list.

Second Approach: Stable

Very similar to the above approach, except we will need 2 pointers to track the right list instead of just one. We need one pointer to keep track of the front and 
one to keep track of the back. Also, we add elements to the back of the right list instead of the front. 
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

ListNode* partitionListUnstable(ListNode* head, int partition) {
  ListNode* left = nullptr;
  ListNode* left_head = nullptr;
  ListNode* right = nullptr;

  while (head) {

    if (head->val >= partition) {
      ListNode* temp = new ListNode(head->val);
      temp->next = right;
      right = temp;
    } else {

      if (!left_head) {
        left = new ListNode(head->val);
        left_head = left;
        left_head->next = left;
      } else {
        left->next = new ListNode(head->val);
        left = left->next;
      }
    }

    head = head->next;
  }

  left->next = right;

  return left_head;
}

ListNode* partitionListStable(ListNode* head, int partition) {
  ListNode* left = nullptr;
  ListNode* left_head = nullptr;
  ListNode* right = nullptr;
  ListNode* right_head = nullptr;

  while (head) {

    if (head->val >= partition) {
      if (!right_head) {
        right = new ListNode(head->val);
        right_head = right;
        right_head->next = right;
      } else {
        right->next = new ListNode(head->val);
        right = right->next;
      }
    } else {

      if (!left_head) {
        left = new ListNode(head->val);
        left_head = left;
        left_head->next = left;
      } else {
        left->next = new ListNode(head->val);
        left = left->next;
      }
    }

    head = head->next;
  }

  left->next = right_head;

  return left_head;
}

int main() {

  int arr[7] = {3, 5, 8, 6, 113, 2, 1};

  ListNode* head = new ListNode(arr[0]);
  ListNode* trav = head;

  for (int i = 1; i < 7; ++i) {
    ListNode* temp = new ListNode(arr[i]);
    trav->next = temp;
    trav = trav->next;
  }

  ListNode* partitioned_list = partitionListStable(head, 5);
  printList(partitioned_list);

  return 0;
}