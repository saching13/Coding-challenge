#include <vector>
#include <queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }
	Node(){
		
	}
  vector<string> breadthFirstSearch(vector<string> *array) {
		queue<Node *> Node_queue;
		Node_queue.push(this);
		Node current;
		while(!Node_queue.empty()){
			current = *Node_queue.front();
			Node_queue.pop();
			array->push_back(current.name);
			for(Node *child_node : current.children) Node_queue.push(child_node);
			
		}
		
		
		return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
