/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, map);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int m1, int n1, vector<int>& inorder, int m2, int n2, unordered_map<int, int>& map) {
        if (m1 > n1) return NULL;
        int curindex = map[preorder[m1]];
        int new_right_m1 = m1 + curindex - m2 + 1;
        TreeNode *root = new TreeNode(preorder[m1]);
        root->left = buildTree(preorder, m1+1, new_right_m1-1, inorder, m2, curindex-1, map);
        root->right = buildTree(preorder, new_right_m1, n1, inorder, curindex+1, n2, map);
        return root;
    }
    