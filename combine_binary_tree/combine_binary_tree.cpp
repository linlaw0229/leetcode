//
//  combine_binary_tree.cpp
//  
//
//  Created by 林威宇 on 2017/7/12.
//
//

#include <stdio.h>
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        
        TreeNode* result= new TreeNode(0);
        result->val= (t1 == NULL ? NULL : t1->val) + (t2 == NULL ? NULL : t2->val);
        
        result->left= mergeTrees(t1 == NULL ? 0 : t1->left, t2 == NULL ? 0 : t2->left);
        result->right= mergeTrees(t1 == NULL ? 0 : t1->right, t2 == NULL ? 0 : t2->right);
        
        return result;
    }
};


/* better solution
 class Solution {
 public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL) return t2;
        if (t2==NULL) return t1;
    
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
    return t1;
    }
 };
*/
