/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
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

/*int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int result = depth(root->left) + depth(root->right);
        printf("%d\n", result);
        return max(result, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int depth(TreeNode* root){
        if(!root) return 0;
        
        return 1 + max(depth(root->right), depth(root->left));
    }
    */

public:
    int _recurse(TreeNode* root, int &ans) {
        if (!root->left && !root->right) {
            return 0;
        }
        
        int left = 0, right = 0;
        if (root->left) left = _recurse(root->left, ans) + 1;
        if (root->right) right = _recurse(root->right, ans) + 1;
        
        if (left + right > ans) {
            ans = left + right;
        }
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        _recurse(root, ans);
        return ans;
    }
};
