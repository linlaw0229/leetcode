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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vSmallest;
        Smallestkth(root,k,vSmallest);
        return vSmallest[k-1];
    }
    void Smallestkth(TreeNode* root, int k,vector<int> &vSmallest)
    {
        if(root->left) Smallestkth(root->left,k,vSmallest);
        vSmallest.push_back(root->val);
        if(root->right) Smallestkth(root->right,k,vSmallest);
    }
};