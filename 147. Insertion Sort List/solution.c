/*
Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        ListNode result(INT_MIN);
        
        while(head){
            ListNode* iter = &result;
            while(iter->next && (iter->next->val < head->val)){
                iter = iter->next;
            }
            ListNode* next = head->next;
            head->next = iter->next;
            iter->next = head;
            head = next;
        }
        return result.next;
    }
};
