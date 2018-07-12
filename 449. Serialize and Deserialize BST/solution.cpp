/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:
    /*
    1. decide what to store the serialized data, stringstream is better because it can auto allocate memory
    2. use preorder to store the tree structure
    3. each node will be separated by " ", NULL will be illustrated in "# ". The space is for stringstream
    */

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serial(root, os);
        return os.str();
    }
    
    void serial(TreeNode* root, ostringstream& os){
        if(!root) os<< "# "; //end signal
        else{
            os << root->val<< " ";
            serial(root->left, os);
            serial(root->right, os);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserial(is);
    }
    
    TreeNode* deserial(istringstream &is){
        string val= "";
        is>> val;
        if(val == "#"){
            return NULL;
        }
        else{
            TreeNode* tmp= new TreeNode(stoi(val));
            tmp->left= deserial(is);
            tmp->right= deserial(is);
            return tmp;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));