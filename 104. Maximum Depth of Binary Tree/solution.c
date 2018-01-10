class Solution { //beat 15% people
public:
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
    int depth(TreeNode* p, int level){
        if(p == NULL) 
            return level;
        
        level++;
        auto L= depth(p->left, level);
        auto R= depth(p->right, level);
        return (L>=R)? L:R;
        
    }
};

class Solution{
public: 
    int maxDepth(TreeNode* root) {
       	if (!root) return 0;
    	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }	
	
}
