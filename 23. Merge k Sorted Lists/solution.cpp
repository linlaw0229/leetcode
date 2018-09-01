/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //divide lists into half, merge every two list together until only one left
        if(lists.empty()) return NULL;
        int n= lists.size();
        while(n>1){
            int k= (n+1)/2;
            for(int i= 0; i< n/2; i++){
                lists[i]= mergeList(lists[i], lists[i+k]);
            }
            n= k;
        }
        return lists[0];
    }
    
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* head= new ListNode(-1);
        ListNode* cur= head;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next= l1;
                l1= l1->next;
            }
            else{
                cur->next= l2;
                l2= l2->next;
            }
            cur= cur->next;
        }
        
        if(l1)
            cur->next= l1;
        if(l2)
            cur->next= l2;
        
        return head->next;
    }
};