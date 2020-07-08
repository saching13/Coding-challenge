// Method 1 using DFS and visiting and visited like in topological sort.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        unordered_set<int> safe_nodes;
        vector<bool> visiting(graph.size(), false);

        
        for(int i = 0; i < graph.size(); ++i){
            if(!visited[i]){
                bool is_safe = dfs(i, graph, visited, visiting, safe_nodes);
                if(is_safe){
                    safe_nodes.insert(i);
                }
            }
        }
        vector<int> safe_node_list(safe_nodes.begin(), safe_nodes.end());
        sort(safe_node_list.begin(), safe_node_list.end());
        return safe_node_list;
        // return {safe_nodes.begin(), safe_nodes.end()};
    }
    
    bool dfs(int node, 
             vector<vector<int>>& graph, 
             vector<bool>& visited, 
             vector<bool>& visiting, 
             unordered_set<int>& safe_nodes){
        
       // bool is_safe = true;;
        
        if(visiting[node]) return false;
        visiting[node] = true;
        vector<int> edges(graph[node]);
        
        for(int i = 0; i < edges.size(); ++i){
            
            if(visited[edges[i]]){
                if(safe_nodes.find(edges[i]) == safe_nodes.end()){
                    visited[node] = true;
                    visiting[node] = false;
                    return false;
                }
            }
            else{
                if(!dfs(edges[i], graph, visited, visiting, safe_nodes)){
                    visited[node] = true;
                    visiting[node] = false;
                    return false;
                }
            }
        }
        visiting[node] = false;
        visited[node] = true;
        safe_nodes.insert(node);
        return true;
           
    }
    
};



// Method 2: same as first but tinly increase in speed by eleminating sorting ans use of sets. 
// insted used int vector for visited to mention different states of the nodes
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);
        unordered_set<int> safe_nodes;
        vector<bool> visiting(graph.size(), false);

        
        for(int i = 0; i < graph.size(); ++i){
            if(visited[i] == 0){
                dfs(i, graph, visited, visiting, safe_nodes);

                }
            }
        
        vector<int> safe_node;
    
        for(int i = 0; i < visited.size(); ++i){
            if(visited[i] == 1)
                safe_node.push_back(i);
        }
        
        
        return safe_node;
    }
    
    bool dfs(int node, 
             vector<vector<int>>& graph, 
             vector<int>& visited, 
             vector<bool>& visiting, 
             unordered_set<int>& safe_nodes){
        
        
        if(visiting[node]) return false;
        visiting[node] = true;
        vector<int> edges(graph[node]);
        
        for(int i = 0; i < edges.size(); ++i){
            
            if(visited[edges[i]] == -1){
                // if(safe_nodes.find(edges[i]) == safe_nodes.end()){
                    visited[node] = -1;
                    visiting[node] = false;
                    return false;
                // }
            }
            else if(visited[edges[i]] == 1){
                continue;
            }
            else{
                if(!dfs(edges[i], graph, visited, visiting, safe_nodes)){
                    visited[node] = -1;
                    visiting[node] = false;
                    return false;
                }
            }
        }
        visiting[node] = false;
        visited[node] = 1;
        // safe_nodes.insert(node);
        return true;
           
    }
    
};