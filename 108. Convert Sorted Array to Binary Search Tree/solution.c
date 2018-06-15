/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return NULL;
        TreeNode* head= helper(nums, 0, nums.size()-1);
        return head;
    }
    
    TreeNode* helper(vector<int>& nums, int low, int high){
        if(low > high) return NULL;
        
        int mid= (low+high)/2;
        //int mid= low +(high-low)/2;
        //this can avoid int overflow
        
        TreeNode* node= new TreeNode(nums[mid]);
        node->left= helper(nums, low, mid-1);
        node->right= helper(nums, mid+1, high);
        return node;
    }
};