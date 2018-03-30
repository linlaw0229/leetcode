/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

//This solution use O(n) space.

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        
        ListNode *node = head;
        while(node){
            if(visited.find(node) != visited.end())
                return node;
            visited.insert(node);
            node = node->next;
            
        }
        return NULL;
    }
};
