/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4
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
    int countUnivalSubtrees(TreeNode* root) {
            int count = 0;
            helper(root, count);
            return count;
        }
        
        bool helper(TreeNode* root, int& count)
        {
            if(root == NULL) return true;
            
            auto isLeft = helper(root->left, count);
            auto isRight = helper(root->right, count);
            
            if(isLeft && isRight
                && ((root->left == NULL) || root->left->val == root->val)
                && ((root->right == NULL) || root->right->val == root->val)
            )
            {
                count++;
                return true;
            }
            return false;
        }
};