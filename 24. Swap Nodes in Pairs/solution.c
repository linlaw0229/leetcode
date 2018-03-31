/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11046/My-simple-JAVA-solution-for-share/11919
https://goo.gl/kG8Rzv

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* newhead = new ListNode(INT_MIN);
        newhead->next = head;
        ListNode* tmp = newhead;
        
        ListNode *one = NULL, *two = NULL;
        
        while(tmp->next && tmp->next->next){
            one = tmp->next;
            two = tmp->next->next;
            
            one->next = two->next;
            two->next = one;
            tmp->next = two;
            tmp = one;
        }
        return newhead->next;
    }
};
