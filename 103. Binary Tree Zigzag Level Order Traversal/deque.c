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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        deque<TreeNode*> deq;
        deq.push_back(root);
        int iszig=1;
        
        while(!deq.empty()) {
            int sz=deq.size();
            iszig=iszig^1;
            vector<int> row;
            while(sz--) {
                if(iszig) { // pop_front, push_back, right then left
                    root=deq.front();deq.pop_front();
                    row.push_back(root->val);
                    if(root->right) deq.push_back(root->right);
                    if(root->left) deq.push_back(root->left);
                }
                else { // pop_back, push_front, left then right
                    root=deq.back();deq.pop_back();
                    row.push_back(root->val);
                    if(root->left) deq.push_front(root->left);
                    if(root->right) deq.push_front(root->right);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
