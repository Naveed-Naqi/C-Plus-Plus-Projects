#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/*
Palindrome: Implement a function to check if a linked list is a palindrome. 

First Approach: With Reversed List
First reverse the list and just compare one with the other.

*/

void printList(ListNode* head_ptr) {

  while (head_ptr) {
    cout << head_ptr->val << "\t";
    head_ptr = head_ptr->next;
  }

  cout << "\n";
}

ListNode* reverseList(ListNode* head) {

  if (!head || !head->next) {
    return head;
  }

  ListNode* reversedHead = new ListNode(head->val);
  head = head->next;

  while (head) {
    ListNode* temp = new ListNode(head->val);
    temp->next = reversedHead;
    reversedHead = temp;
    head = head->next;
  }

  return reversedHead;
}

bool isPalindromeWithReversedList(ListNode* head) {
  ListNode* reversed_head = reverseList(head);

  while (head) {
    if (head->val != reversed_head->val) {
      return false;
    }

    head = head->next;
    reversed_head = reversed_head->next;
  }

  return true;
}

bool isPalindromeWithStack(ListNode* head) {
  stack<int> list;

  if (!head || !head->next) {
    return true;
  }

  ListNode* slow = head;
  ListNode* fast = head;

  while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    list.push(slow->val);
    slow = slow->next;
  }

  bool isOdd = fast->next == nullptr;
  if (isOdd) {
    slow = slow->next;
  } else {
    list.push(slow->val);
    slow = slow->next;
  }

  while (slow) {

    if (list.empty()) {
      return false;
    }

    int val = list.top();

    if (val != slow->val) {
      return false;
    }

    list.pop();
    slow = slow->next;
  }

  return list.empty();
}

int main() {

  int arr[7] = {1, 2, 3, 4, 3, 2, 1};

  ListNode* head_ptr = new ListNode(arr[0]);
  ListNode* trav_ptr = head_ptr;

  for (int i = 1; i < 7; ++i) {
    trav_ptr->next = new ListNode(arr[i]);
    trav_ptr = trav_ptr->next;
  }

  printList(head_ptr);

  cout << isPalindromeWithStack(head_ptr);

  return 0;
}