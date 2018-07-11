/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
//DFS solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(res, root, 0);
        return res;
    }
    
    void helper(vector<int>& res, TreeNode* cur, int depth){
        if(!cur) return;
        
        if(depth == res.size()){
            res.push_back(cur->val);
        }
        
        helper(res, cur->right, depth+1);
        helper(res, cur->left, depth+1); //if a root have right and left node, the right node will add to res already, so left will not be pushed into res.
    }
};