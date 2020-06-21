using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

void dfs(BinaryTree *root, int sum, vector<int>& branchSum){
	//if(root == NULL) return;
	//cout << root->value << endl;
	if(root->left == NULL && root->right == NULL) branchSum.push_back(sum + root->value);
	if(root->left != NULL) dfs(root->left, sum + root->value, branchSum);
	
	if(root->right != NULL) dfs(root->right, sum + root->value, branchSum);
	
	return;
}

vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
	vector<int> branchSum;
	if(root == NULL) return {};
	dfs(root, 0, branchSum);
	//for(int sum : branchSum) cout << sum << " ";
	
  return branchSum;
}
