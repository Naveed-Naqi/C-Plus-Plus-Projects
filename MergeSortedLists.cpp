/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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

    ListNode* CreateFirstNode(ListNode*& l1_traversal, ListNode*& l2_traversal) {

        ListNode* first_node;

        if(l1_traversal == nullptr && l2_traversal != nullptr) {
            first_node = new ListNode(l2_traversal->val);
        }
        else if (l1_traversal != nullptr && l2_traversal == nullptr) { 
            first_node = new ListNode(l1_traversal->val);
        }
        else if(l1_traversal != nullptr && l2_traversal != nullptr) {
            
            if (l1_traversal->val < l2_traversal->val) {
                first_node = new ListNode(l1_traversal->val);
                l1_traversal = l1_traversal->next;
            }
            else {
                first_node = new ListNode(l2_traversal->val);
                l2_traversal = l2_traversal->next;
            }            
        }        

        return first_node;
    }

    void AddRemainingElements(ListNode*& l1_traversal, ListNode*& l2_traversal, ListNode*& sorted_list_traversal) {

        if(l1_traversal == nullptr) {

            while(l2_traversal != nullptr) {
                sorted_list_traversal->next = new ListNode(l2_traversal->val);
                l2_traversal = l2_traversal->next;
                sorted_list_traversal = sorted_list_traversal->next;
            }
        }
        else {

            while(l1_traversal != nullptr) {
                sorted_list_traversal->next = new ListNode(l1_traversal->val);
                l1_traversal = l1_traversal->next;
                sorted_list_traversal = sorted_list_traversal->next;
            }
        }
    }

    void FillUpSortedList(ListNode*& l1_traversal, ListNode*& l2_traversal, ListNode*& sorted_list_traversal) {

        while(l1_traversal != nullptr && l2_traversal != nullptr) {

            if (l1_traversal->val < l2_traversal->val) {
                sorted_list_traversal->next = new ListNode(l1_traversal->val);
                l1_traversal = l1_traversal->next;
            }
            else {
                sorted_list_traversal->next = new ListNode(l2_traversal->val);
                l2_traversal = l2_traversal->next;
            }

            sorted_list_traversal = sorted_list_traversal->next;   
        }
    }

    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1_traversal = l1;
        ListNode* l2_traversal = l2;
        ListNode* sorted_list_head;

        if(l1_traversal == nullptr && l2_traversal == nullptr) {
            return nullptr;
        }
        else if(l1_traversal == nullptr) {
            return l2_traversal;
        }
        else if(l2_traversal == nullptr) {
            return l1_traversal;
        }

        sorted_list_head = CreateFirstNode(l1_traversal, l2_traversal);
        
        ListNode* sorted_list_traversal = sorted_list_head;

        FillUpSortedList(l1_traversal, l2_traversal, sorted_list_traversal);
        AddRemainingElements(l1_traversal, l2_traversal, sorted_list_traversal);

        return sorted_list_head;
    }

    ListNode* MergeListsAlternative(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy; 
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        while(l1 && l2) {

            if(l1->val>l2->val) {

                l3->next = l2;
                l2= l2->next;
            }
            else {
                l3->next = l1;
                l1=l1->next;
            }
            
            l3 = l3->next;
        }
        
        if(!l1){l3->next=l2;}
        else {l3->next=l1;}
        
        return dummy->next;
    }
};

ListNode* NewNode(int val) {
    ListNode* new_elem = new ListNode(val);
    return new_elem;
}

int main()
{
    ListNode* test_list1 = new ListNode(0);
    ListNode* test_list2 = new ListNode(1);
    ListNode* traversal_ptr = test_list1;

    
    traversal_ptr->next = NewNode(3);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(7);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(21);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(26);
    traversal_ptr = traversal_ptr->next;



    traversal_ptr = test_list2;

    traversal_ptr->next = NewNode(1);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(2);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(7);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(9);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(10);
    traversal_ptr = traversal_ptr->next;

    traversal_ptr->next = NewNode(20);
    traversal_ptr = traversal_ptr->next;
    


    Solution solution;

    ListNode* sorted_list = solution.MergeListsAlternative(test_list1, test_list2);
    solution.PrintList(sorted_list);
    

}