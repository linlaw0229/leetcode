/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
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
    ListNode* plusOne(ListNode* head) {
        
        ListNode* dmy = new ListNode(0);
        ListNode* lastNot9 = dmy;
        dmy->next = head;
        for (ListNode* n = head; n != NULL; n = n->next) {
            if (n->val != 9) lastNot9 = n; /* invariant: [lastNot9.next, tail] are all 9*/
        }
        
        lastNot9->val++;
        for (ListNode* n = lastNot9->next; n != NULL; n = n->next) {
            n->val = 0;
        }
        return dmy->val == 1 ? dmy : head;        
    }
};