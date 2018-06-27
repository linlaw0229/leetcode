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
    int rob(TreeNode* root) {
        vector<int> res= robSub(root);
        return max(res[0], res[1]);
    }
    
    vector<int> robSub(TreeNode* root){
        if(!root) return vector<int>(2,0);
        vector<int> res(2, 0); //0: w/o root. 1: w/ root
        
        vector<int> left= robSub(root->left);
        vector<int> right= robSub(root->right);
        // result without root = add left[1](include left->val) and right[1](include right->val)
        // but maximum value could be bypass root->left or root->right
        // example:
        // 4-1-1-3
        res[0]= max(left[0], left[1])+ max(right[0], right[1]); 
        
        res[1]= root->val+left[0]+right[0];
        
        return res;
    }
    
};