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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow= head, *fast= head;
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        /*
        reverse the second half list
        ex: first half: 1->2->3, 
        ori second half: 3->2->1
        */
        ListNode *last= slow->next;
        while(last->next){
            ListNode *tmp= last->next;
            last->next= tmp->next;
            tmp->next= slow->next;
            slow->next= tmp;
        }
        
        //compare the 
        ListNode *pre= head;
        while(slow->next){
            slow= slow->next;
            if(pre->val != slow->val) return false;
            pre= pre->next;
        }
        return true;
    }
};