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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s,t);
        
    }
    
    bool equals(TreeNode* x, TreeNode* y) {
        
        if(x==NULL && y==NULL)
            return true;
        if(x==NULL || y==NULL)
            return false;
        
        return x->val==y->val && equals(x->left,y->left) && equals(x->right,y->right);
        
        
    }
    
    bool traverse(TreeNode* a, TreeNode* b) {
        
        return  a!=NULL && ( equals(a,b) || traverse(a->left,b) || traverse(a->right,b));
                
    }
    
    
    
};