/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        example 1: same length of A, B
            A1->A2->C1->C2->C3
            B1->B2->C1->C2->C3
            will meet in first iteration
            
        example 2: diff length of A, B
            A1->A2->A3->C1->C2->C3
            B1->B2->C1->C2->C3
            
            let B go from A after it meets NULL,
            A1->A2->A3->C1->C2->C3->B1->B2->C1->C2->C3
            B1->B2->C1->C2->C3->A1->A2->A3->C1->C2->C3
                                            |
                                            will meet in second iteration
        */
        ListNode *p1= headA, *p2= headB;
        if(!headA || !headB) return NULL;
        
        while(p1 && p2 && p1 != p2){ //terminate when p1== NULL && p2== NULL
            p1= p1->next;
            p2= p2->next;
            if(p1== p2) return p1; //value and next both equal
            
            if(!p1) p1= headB;
            if(!p2) p2= headA;
        }
        return p1;
    }
};