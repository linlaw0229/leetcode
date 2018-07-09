/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, sum, root);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& tmp, int sum, TreeNode* root){
        if(!root) return;
        
        tmp.push_back(root->val);
        //preorder traversal
        if(!root->left && !root->right && sum-root->val ==0) res.push_back(tmp);
        if(root->left) helper(res, tmp, sum-root->val, root->left);
        if(root->right) helper(res, tmp, sum-root->val, root->right);
        tmp.pop_back();
    }
};