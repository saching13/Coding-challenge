// Two methods shown here

// 1) Togoplogiacal sort using dfs where we use two bools one for visited and one for visiting.

#include <vector>
using namespace std;

class JobNode {
	
	public:
		int job;
		vector<JobNode *> preReqs;
		bool visited;
		bool visiting;
	
	JobNode(int jobName):job(jobName),visited(false),visiting(false){
		}
	
	void addPreReq(JobNode* preReq){
		preReqs.push_back(preReq);
	}
	
};

class CreateGraph{
	
	public: 
	vector<JobNode *> nodes;
	unordered_map<int, JobNode *> graphList;
	
	CreateGraph(vector<int> jobs, vector<vector<int>> deps){
		addNodes(jobs);
		addPreReqs(deps);
	}
	
	
	void addNodes(vector<int> jobs){
		for(int job : jobs){
			JobNode* node = new JobNode(job);
			nodes.push_back(node);
			graphList[job] = node;
		}
	}
	
	void addPreReqs(vector<vector<int>> deps){
		// [x,y] y depends on x => x is prereq of y
		for(vector<int>& dep : deps){
			JobNode* preReq = graphList[dep[0]];
			JobNode* curr = graphList[dep[1]];
			curr->addPreReq(preReq);
		}
	}
	
	JobNode* getNode(){
		JobNode* node = nodes.back();
		nodes.pop_back();
		return node;
	}
};


bool dfs(JobNode* node, vector<int>& orderedList){
	if(node->visited) return true;
	if(node->visiting) return false;
	
			node->visiting = true;
		for(JobNode* nextNode : node->preReqs){
			if(!dfs(nextNode, orderedList)) return false;
		}
		node->visiting = false;
		node->visited = true;
		orderedList.push_back(node->job);
	
	// if(node->preReqs.empty()){
	// 	orderedList.push_back(node->job);
	// 	node->visited = true;
	// 	return true;
	// }
	// else{
	// 	node->visiting = true;
	// 	for(JobNode* nextNode : node->preReqs){
	// 		if(!dfs(nextNode, orderedList)) return false;
	// 	}
	// 	node->visiting = false;
	// 	node->visited = true;
	// 	orderedList.push_back(node->job);
	// }
	
	return true;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // Write your code here.
	vector<int> orderedList;
	CreateGraph graph = CreateGraph(jobs, deps);
	
	while(!graph.nodes.empty()){
		
		JobNode* node = graph.getNode();
		if(!dfs(node, orderedList)){
 				return {};
		}

	}
	return orderedList;
}



/* Method 2) Topological sort by removing edges: 
HINT: In this we create a data structure where each node contains the list of 
jobs that are depenednt on it so that when we remove all the edges from that last node 
which has zero dependency we will update all those nodes which are dependent on it that 
it has one less dependent */

#include <vector>
using namespace std;

class JobNode {
	
	public:
		int job;
		vector<JobNode *> deps;
		int preReq;
	JobNode(int jobName):job(jobName),preReq(0){
		}
	
	void addDep(JobNode* dep){
		deps.push_back(dep);
	}
	
};

class CreateGraph{
	
	public: 
	vector<JobNode *> nodes;
	unordered_map<int, JobNode *> graphList;
	
	CreateGraph(vector<int> jobs, vector<vector<int>> deps){
		addNodes(jobs);
		addDeps(deps);
	}
	
	
	void addNodes(vector<int> jobs){
		for(int job : jobs){
			JobNode* node = new JobNode(job);
			nodes.push_back(node);
			graphList[job] = node;
			
		}
	}
	
	void addDeps(vector<vector<int>> deps){
		// [x,y] y depends on x => x is prereq of y
		for(vector<int>& dep : deps){
			JobNode* dependent = graphList[dep[1]];
			JobNode* curr = graphList[dep[0]];
			dependent->preReq++;
			curr->addDep(dependent);
		}
	}
	
	JobNode* getNode(){
		JobNode* node = nodes.back();
		nodes.pop_back();
		return node;
	}
	
	vector<JobNode*> getNoPrereqNodes(){
		vector<JobNode*> nodeWithoutPreReq;
		for(JobNode* node : nodes){
			if(node->preReq == 0) nodeWithoutPreReq.push_back(node);
		}
		return nodeWithoutPreReq;
	}
};


void updateNodes(JobNode* node,vector<JobNode*>& nodeWithoutPreReq){
	for(JobNode* depNode : node->deps){
		depNode->preReq--;
		if(depNode->preReq == 0)nodeWithoutPreReq.push_back(depNode);
	}
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // Write your code here.
	vector<int> orderedList;
	CreateGraph graph = CreateGraph(jobs, deps);
	
	vector<JobNode*> nodeWithoutPreReq = graph.getNoPrereqNodes();
	if(nodeWithoutPreReq.empty()) return {};
	
	while(!nodeWithoutPreReq.empty()){
		JobNode* node = nodeWithoutPreReq.back();
		nodeWithoutPreReq.pop_back();
		orderedList.push_back(node->job);
		updateNodes(node, nodeWithoutPreReq);
	}
	
	for(JobNode* node : graph.nodes){
		if(node->preReq > 0) return {};
	}
	
	
	return orderedList;
}



