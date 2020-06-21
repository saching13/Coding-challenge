// Iteratice inorder traversal using DFS

#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = NULL);
  void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) {
  // Write your code here.
	deque<BinaryTree*> nodes;
	BinaryTree* head = tree;
	nodes.push_front(tree);
	int i = 0;
	vector<int> visited;
	while(!nodes.empty()){
		BinaryTree* currNode = nodes.front();
		//cout << currNode->value << " current Node"<< endl;
		i++;
		//if(i == 7) break;
		
		if(currNode->left != NULL && 
				std::find(visited.begin(),
									visited.end(),
									currNode->left->value) == visited.end()){
			
			nodes.push_front(currNode->left);
		}
		else {
			callback(currNode);
			visited.push_back(currNode->value);
			cout << "visited" << currNode->value << endl;
			nodes.pop_front();
			if(currNode->right != NULL) nodes.push_front(currNode->right);
		}
	}
	
}
