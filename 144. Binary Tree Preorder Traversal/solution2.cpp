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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(!root) return res;
        stk.push(root);
        
        while(!stk.empty()){
            auto top= stk.top();
            res.push_back(top->val);
            stk.pop();
            if(top->right) stk.push(top->right);
            if(top->left) stk.push(top->left);
        }
        return res;
    }
};