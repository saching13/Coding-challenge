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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int len = pre.size();
        if(len == 0) return NULL;

        TreeNode* root;
        //if(len == 1) return root(pre[0]);
        
        
        root = recursiveTree(0, len - 1, 0, len - 1, pre, post);
        
        return root;
        
    }
    
    TreeNode* recursiveTree(int l1, int l2, int r1, int r2, vector<int>& pre, vector<int>& post){
        //cout << "l1 :" << l1 << " l2: " << l2 << " r1: " << r1 << " r2: " << r2 << endl;

        if(l2 - l1 + 1 == 0) return NULL;
        TreeNode* root = new TreeNode(pre[l1]);
        if(l2 - l1 + 1 == 1) return root;
        int N = r2 - r1 + 1;
        int offset;
        for(int i = 0;i < N; ++i){
            if(pre[l1 + 1] == post[r1 + i])
                offset =  i + 1;
        }
        
        root->left = recursiveTree(l1 + 1, l1 + offset, r1, r1 + offset - 1, pre, post);
        //cout << "right" <<endl;
        root->right = recursiveTree(l1 + offset + 1, l2, r1 + offset, r2 - 1, pre, post);
        
        return root;    
    }
};