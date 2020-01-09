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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return judge(root, NULL,NULL);
    }
    
    bool judge(TreeNode* tp, TreeNode* min, TreeNode* max){
        if(!tp) return true;
        if((min != NULL && tp->val <= min->val) || (max != NULL && tp->val >= max->val))
            return false;
        return judge(tp->left, min, tp) && judge(tp->right, tp, max);
    }
};