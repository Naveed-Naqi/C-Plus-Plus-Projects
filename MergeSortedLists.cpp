/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* l1_traversal = l1;
        ListNode* l2_traversal = l2;

        ListNode* sorted_list(0);
        ListNode* sorted_list_head = sorted_list;

        if(l1_traversal->val < l2_traversal->val)
        {
            sorted_list = new ListNode(l1_traversal->val);
            l1_traversal = l1_traversal->next;
        }
        else
        {
            sorted_list = new ListNode(l2_traversal->val);
            l2_traversal = l2_traversal->next;
        }

        sorted_list = sorted_list->next;

        while(l1_traversal->next != nullptr && l2_traversal->next != nullptr)
        {
            if(l1_traversal->val < l2_traversal->val)
            {
                sorted_list->next = new ListNode(l1_traversal->val);
                l1_traversal = l1_traversal->next;
            }
            else
            {
                sorted_list->next = new ListNode(l2_traversal->val);
                l2_traversal = l2_traversal->next;
            }

            sorted_list = sorted_list->next;
        }

        l1_traversal->next == nullptr ? enterRemainingElements(l2_traversal, sorted_list) : enterRemainingElements(l1_traversal, sorted_list);

        return sorted_list_head;
    }

    void insertFirstItem(ListNode* l1_traversal, ListNode* l2_traversal, ListNode* sorted_list)
    {
       if(l1_traversal->val < l2_traversal->val)
        {
            sorted_list = l1_traversal;
            l1_traversal = l1_traversal->next;
        }
        else
        {
            sorted_list = l2_traversal;
            l2_traversal = l2_traversal->next;
        }

        sorted_list = sorted_list->next;
    }

    void enterRemainingElements(ListNode* traversal, ListNode* sorted_list)
    {
        while(traversal->next != nullptr)
        {
            sorted_list->next = traversal;
            traversal = traversal->next;
        }
    }
};

int main()
{

}