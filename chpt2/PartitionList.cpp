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

Other edge cases that I did not orginally think about were what happens when the first or second list is null. 
I might need to write many if statements that account for this kind of situation, or go weith a different implementation of my appraoch entirely.

I have learned a valuable lesson about being very acutely aware of edge cases in which case stuff is empty and how best to deal with it. 
I should conduct more extensive testing with my solutions or run them through leetcode in the future in order to get a better bearing on how these solutions may be broken.
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

ListNode* partitionListStable(ListNode* head, int x) {
  ListNode* left_head = new ListNode(0);
  ListNode* left = left_head;
  ListNode* right_head = new ListNode(0);
  ListNode* right = right_head;

  if (!head || !head->next) {
    return head;
  }

  while (head) {
    if (head->val < x) {
      left->next = head;
      left = left->next;
    } else {
      right->next = head;
      right = right->next;
    }

    head = head->next;
  }

  right->next = nullptr;
  left->next = right_head->next;

  return left_head->next;
}

int main() {

  int arr[7] = {1, 2};

  ListNode* head = new ListNode(arr[0]);
  ListNode* trav = head;

  for (int i = 1; i < 2; ++i) {
    ListNode* temp = new ListNode(arr[i]);
    trav->next = temp;
    trav = trav->next;
  }

  ListNode* partitioned_list = partitionListStable(head, 2);
  printList(partitioned_list);

  return 0;
}