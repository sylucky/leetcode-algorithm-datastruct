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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return false;
        
        int val=root->val;
        
        return PreOrderTree(root,val);
    }
    //先序遍历
    bool PreOrderTree(TreeNode* root,int val){
        if(root==NULL)
            return true;
        
        if(val!=root->val)
            return false;

        
        return PreOrderTree(root->left, val) && PreOrderTree(root->right, val);
    }
};