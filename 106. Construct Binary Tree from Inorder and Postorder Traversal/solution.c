/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return deal(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }
    
    TreeNode* deal(int leftInorder, int rightInorder, int leftPostorder, int rightPostorder, vector<int>& inorder, vector<int>& postorder) {
        if (rightInorder < leftInorder || rightPostorder < leftPostorder) return NULL;
        
        // 生成根节点
        TreeNode* rt = new TreeNode(postorder[ rightPostorder ]);

        // 找到根在中序遍历中的位置
        int p = 0;
        for (int i = 0; i <= rightInorder - leftInorder; ++i)
            if (inorder[leftInorder + i] == rt -> val) {
                p = i; break;
            }

        // 递归处理两个子树
        rt -> left  = deal(leftInorder, leftInorder + p - 1, leftPostorder, leftPostorder + p - 1, inorder, postorder);
        rt -> right = deal(leftInorder + p + 1, rightInorder, leftPostorder + p, rightPostorder - 1, inorder, postorder);

        // 返回根节点
        return rt;
    }
    
};
