/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct comp{
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        for(int i= 0; i< lists.size(); i++){
            if(lists[i]) q.push(lists[i]);
        }
        
        ListNode* head= new ListNode(-1);
        ListNode *cur= head, *tmp= NULL;
        while(!q.empty()){
            tmp= q.top(); //it's the smallest element right now
            q.pop();
            cur->next= tmp;
            cur = cur->next;
            if(tmp->next) q.push(tmp->next);
        }
        return head->next;
    }
};
