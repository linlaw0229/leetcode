/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        Binary search tree:
        root->val < any right subtree node value
        root->val > any left subtree node value
        */
        TreeNode* cur= root;
        while(true){
            if(cur->val > q->val && cur->val >p->val)
                cur= cur->left;
            else if(cur->val < q->val && cur->val < p->val)
                cur= cur->right;
            else
                return cur;
        }
    }
};