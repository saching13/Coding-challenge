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
    vector<int> rightSideView(TreeNode* root) {
        //unordered_map<string, int> umap; 
        vector<int> result; // create an empty array with index being the level
        
        if (current == NULL)
            return result;
        
        dfs(root,result,0); // recursive call to dfs

        return result;
    }
    
    
    
    
     void dfs(TreeNode* node, vector<int>& res,int level){
         
         if (node != NULL){
             
             if (res.size() == level)
                 res.push_back(node->val); 
             // since level 0 is considered as starting point when size is zero it contains 
             // nothing and we will add the root node values
             
             // as we do right node first and if the node contains vale it will 
             // be added to the appropriate level in the vector since its the first visit.
             // when second visit occurs length will be increased by 1 due to push_back into the vector
             dfs(node->right,res,level+1);
             dfs(node->left,res,level+1);
             
             
             
         }
             
         
         
     }
         
    
};