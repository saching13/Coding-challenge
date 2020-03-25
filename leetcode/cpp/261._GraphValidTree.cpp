//  261 Graph Valid Tree
// TODO:How does it work?
// Hint: in Graph theory a;l the nodes in the graph are not always fully connected
// to check if a valid tree is present the first condition would be to check if the graph is fully connected.
// But graph can be fully connected only if the number of edges == number of nodes - 1
// so once we are sure we can check using DFS if the graph is fully connected.
// Now if we are sure if it is fully connected how to check if it is a tree or not.
// one intusion is that if a graph has n-1 edges and fully connected there is nowhere left to have an extra edge to make it a cyclic so 
// if a graph has n-1 edges then we just need to check if it is fully connected or not
// example 5 nodes. edges = [[0,1], [2,3], [3,4], [4,2]] --> not fully connected 


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        else if (edges.size() == 0 && n == 1) return true;
        else if (n == 0) return false;
        std::vector<std::vector<int>> adjList(n);
        
        for(std::vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        
        std::queue<int> nodeQueue;
        std::set<int> visited;
        nodeQueue.push(0);
        visited.insert(0);
       
        while(!nodeQueue.empty()){
            int node = nodeQueue.front();
            nodeQueue.pop();
            for(int neigh : adjList[node]){
                if(visited.find(neigh) != visited.end()) continue;
                visited.insert(neigh);
                nodeQueue.push(neigh);
            }
        }
        
   
        return(visited.size() == n);
    }
};