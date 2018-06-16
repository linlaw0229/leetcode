/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        dfs(root, result);
        return result;
    }
    
    int dfs(TreeNode* root, int& result){
        if(!root) return 0;
        int left=max(0, dfs(root->left, result));
        int right=max(0, dfs(root->right, result));
        result= max(result, left+right+root->val);
        return max(left, right)+root->val;
    }
};