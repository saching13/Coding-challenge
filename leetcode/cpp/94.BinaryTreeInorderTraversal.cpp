/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Method 1: recursive approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        rec(root, res);
        return res;
    }
    
    void rec(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        rec(root->left, res);
        res.push_back(root->val);
        rec(root->right, res);
    }
};

// Method 2: Iterative approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> myStack;
        TreeNode* curr = root;
    
        while(curr!=NULL || !myStack.empty()){
            while(curr != NULL){
                myStack.push(curr);
                curr = curr->left;
            }
            res.push_back(myStack.top()->val);
            curr = myStack.top()->right;
            myStack.pop();
        }
        return res;
    }
    
  
};