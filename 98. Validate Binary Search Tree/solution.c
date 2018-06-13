/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* root, TreeNode* &prev) {//do Inorder traversal
        //1. find toward left until the end
        //2. set this leftest node as prev
        //3. check if prev(left) node is smaller than root
        //4. check right subtree
        if (root == NULL) return true; 
        if (!validate(root->left, prev)) return false;
        if (prev != NULL && root->val <= prev->val ) return false; //previous node is from left side, so it should be smaller      than right side node
        prev = root; 
        return validate(root->right, prev);
    }
};