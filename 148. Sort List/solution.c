/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev= head, *slow= head, *fast= head;
            
        while(fast != NULL && fast->next != NULL){ 
            //fast runs twice than slow, so when fast reach end, prev would be the half
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL; 
        //cut list into half
        //1. head->...->prev->NULL
        //2. slow->...->endNode->NULL
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if (!l1) return l2; 
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};
