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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        lvl_traverse(root,0,result);
        
        return result;
        
    }
    
    void lvl_traverse(TreeNode* root,int level,vector<vector<int>>& res){
        if(root == NULL)
            return;
        
        if(res.size() == level){
            //cout <<level<<"val"<<root->val<<endl;
            vector<int> lev(1,root->val);
            
            res.push_back(lev);
        }
        else{
            
            
            res[level].push_back(root->val);
        }
        
        lvl_traverse(root->left,level+1,res);
        lvl_traverse(root->right,level+1,res);
        
    }
};