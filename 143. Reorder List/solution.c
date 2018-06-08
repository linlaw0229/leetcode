/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        
        //cut the list into half
        //1-2-3-4-5-6
        //    |     |
        //   slow  fast
        ListNode *slow= head, *fast= head;
        while(fast->next && fast->next->next){ 
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        //reverse the second part of the list
        //1-2-3-4-5-6
        //    | |    
        //   mid|  
        //     pre
        ListNode* middle = slow;
        ListNode* preCurrent = slow->next;
        while(preCurrent->next != NULL){ //use preCurrent->next to determine whether if there's more element need to reverse
            ListNode *current = preCurrent->next; 
            preCurrent->next = current->next;
            current->next = middle->next;
            middle->next= current;
        }
        
        slow = head; //first part of the list
        fast = middle->next; //second part of the list
        while(slow != middle){
            middle->next = fast->next;
            fast->next= slow->next;
            slow->next= fast;
            slow= fast->next;
            fast= middle->next;
        }
    }
};
