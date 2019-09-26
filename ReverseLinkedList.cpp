#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    void PrintList(ListNode* head_ptr) {
        ListNode* trav_ptr = head_ptr;

        while(trav_ptr != nullptr) {
            std::cout << trav_ptr->val << std::endl;
            trav_ptr = trav_ptr->next;
        }
    }

    ListNode* ReverseLinkedList(ListNode* head_ptr) {
        ListNode* tail_ptr = head_ptr;

        ListNode* prev = head_ptr;
        ListNode* curr = head_ptr->next;
        ListNode* next = head_ptr->next->next;

        curr->next = prev;
        next->next = curr;
        
        tail_ptr->next = nullptr;

        return next;
    }

};

ListNode* NewNode(int val) {
    ListNode* new_elem = new ListNode(val);
    return new_elem;
}

int main()
{
    ListNode* test_list1 = new ListNode(0);
    ListNode* traversal_ptr = test_list1;

    
    traversal_ptr->next = NewNode(3);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(7);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(21);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(26);
    traversal_ptr = traversal_ptr->next;

    Solution solution;
    solution.PrintList(test_list1);
    ListNode* reversed = solution.ReverseLinkedList(test_list1);
    solution.PrintList(reversed);

}