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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return vector<string>();
        helper(res, "", root);
        return res;
    }
    
    void helper(vector<string>& res, string tmp, TreeNode* root){
        if(!root->left && !root->right) res.push_back(tmp+to_string(root->val));
        if(root->left) helper(res, tmp+to_string(root->val)+"->", root->left);
        if(root->right) helper(res, tmp+to_string(root->val)+"->", root->right);
    }
};