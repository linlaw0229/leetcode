/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy= new ListNode(-1);
        ListNode* dummy2= new ListNode(-1);
        
        ListNode *cur1= dummy, *cur2= dummy2;
        
        while(head){
            if(head->val >= x){
                cur2->next= head;
                cur2= head;
            }
            else{
                cur1->next= head;
                cur1= head;
            }
            head= head->next;
        }
        cur2->next= NULL;
        cur1->next= dummy2->next;
        return dummy->next;
    }
};