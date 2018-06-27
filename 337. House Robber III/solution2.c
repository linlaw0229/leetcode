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
    unordered_map<TreeNode*, int> map; //use map to store every treeNode in the tree, so that we won't have to recalculate
    
    int rob(TreeNode* root) {
        return robSub(root);
    }
    
    int robSub(TreeNode* root){
        if(!root) return 0;
        int val= 0;
        if(map.find(root) != map.end()) return map.at(root);
        
        if(root->right){
            val+= robSub(root->right->right)+ robSub(root->right->left);
        }
        if(root->left){
            val+= robSub(root->left->right)+ robSub(root->left->left);
        }
        
        val = max(root->val+ val, robSub(root->right)+robSub(root->left));
        map[root]= val;
        return val;
    }
    
};