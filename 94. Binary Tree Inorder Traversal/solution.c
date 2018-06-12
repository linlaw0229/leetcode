/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;
        
        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                //put this node in stack, because it's not yet the leftest node
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                //pCurrent is null, either every node in stack or we're at the leftest NULL
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};
