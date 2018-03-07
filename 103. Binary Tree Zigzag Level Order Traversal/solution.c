/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;
        
        stack<TreeNode*> curLevel;// = new stack<TreeNode*>();
        stack<TreeNode*> nextLevel;//= new stack<TreeNode*>();;
        curLevel.push(root);
        bool left2right = true;
        
        while(!curLevel.empty()){
            vector<int> curLevelValues;
            
            while(!curLevel.empty()){
                TreeNode *node = curLevel.top();
                curLevel.pop();
                curLevelValues.push_back(node->val);
                
                if(left2right){
                    if(node->left) nextLevel.push(node->left);
                    if(node->right) nextLevel.push(node->right);
                }
                else{
                    if(node->right) nextLevel.push(node->right);
                    if(node->left) nextLevel.push(node->left);
                }
                
            }
            levelNodeValues.push_back(curLevelValues);
            
            stack<TreeNode*> tmp = curLevel;
            curLevel = nextLevel;
            nextLevel = tmp;
            
            left2right = !left2right;
        }
        
        return levelNodeValues;
    }

};


