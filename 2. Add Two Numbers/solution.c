/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* listNode=new ListNode(0);
        ListNode* p1=l1,*p2=l2,*p3=listNode;

        while(p1!=NULL || p2!=NULL)
        {
            if(p1!=NULL)
            {
                carry+=p1->val;
                p1=p1->next;
            }
            if(p2!=NULL)
            {
                carry+=p2->val;
                p2=p2->next;
            }
            p3->next=new ListNode(carry%10);
            p3=p3->next;
            carry/=10;
        }
        if(carry==1)
            p3->next=new ListNode(1);
        return listNode->next;  
    }
};
