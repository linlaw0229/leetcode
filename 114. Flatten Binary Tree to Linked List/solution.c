/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

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
    void flatten(TreeNode* root) {
        helper(root);
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root) return root;
        if(root->right) helper(root->right);
        if(root->left) helper(root->left);
        
        root->right= prev;
        root->left= NULL;
        prev= root;
        return root;
    }
    TreeNode* prev= NULL;
};