#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode*next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head_ptr) {

  while(head_ptr != nullptr) {
    cout << head_ptr->val << "\t";
    head_ptr = head_ptr->next;
  }

  cout << "\n";
}

ListNode* partition( ListNode* listhead , int x ) {
   ListNode* head = nullptr;
   ListNode* headInitial = nullptr;   /*The initial ListNodeof list head*/
   ListNode* tail = nullptr;
   ListNode* tailInitial = nullptr;   /*The initial ListNodeof list tail*/
   ListNode* curr = listhead;
   while( curr != nullptr ) {
     ListNode* nextNode= curr->next;
     if ( curr->val < x ) {
            if (head == nullptr) {
                head = curr;
                headInitial = head;
            }
       //insert curr ListNodeto head list
       head->next = curr;
       head = curr;
     } else {
            if (tail == nullptr) {
                tail = curr;
                tailInitial = tail;
            }
       // insert curr ListNodeto tail list
       tail->next = curr;
       tail = curr;
     }
     curr = nextNode;
   }
   head->next = tailInitial;  /*Now, we connect the head list to tail list.*/
   tail->next = nullptr;
   return headInitial;
 }

int main() {

  
  int arr[7] = {3, 6, 4, 2, 8, 1, 4};

  ListNode* head = new ListNode(arr[0]);
  ListNode* trav = head;

  for(int i = 1; i < 7; ++i) {
    ListNode* temp = new ListNode(arr[i]);
    trav->next = temp;
    trav = trav->next;
  }
  printList(head);
  ListNode* partitionedList = partition(head, 4);
  printList(partitionedList);

  return 0;
}