/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        TreeLinkNode *head, *cur, *tail;
        cur= root; //cur: current level traveler
        head= tail = NULL; //head: left most element in next level, tail: right most element in next level also used as traveler
        
        while(cur){
            if(cur->left){
                if(!tail) head= tail= cur->left;
                else {
                    tail->next = cur->left;
                    tail= tail->next;
                }
            }
            if(cur->right){
                if(!tail) head= tail= cur->right;
                else {
                    tail->next= cur->right;
                    tail= tail->next;
                }
            }
            
            cur= cur->next; //move to next element in current level
            if(!cur){       //if no next, then point to first element in next level
                cur= head;
                head= tail= NULL;
            }
        }
    }
    
};