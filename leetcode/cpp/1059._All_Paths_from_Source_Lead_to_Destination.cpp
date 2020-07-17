class Solution {
    bool dfs(int curr, int dest, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, vector<bool>& visiting){
        
        if(adj_list.find(curr) == adj_list.end()){
                return curr==dest;
        } 
                visiting[curr] = true;

        for(int sub_node : adj_list[curr]){
            if(!visiting[sub_node]){
                if(visited[sub_node]){
                    continue;
                }
                else{
                    if(!dfs(sub_node, dest, adj_list, visited, visiting))
                        return false;
                }   
            }
            else{
                return false;
            }
        }
        
        visited[curr] = true;
        visiting[curr] = false;
        return true;
        
    }
    
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> adj_list;
        // int max_nodes = INT_MIN;
        
        for(int i = 0; i < edges.size(); ++i){
            adj_list[edges[i][0]].push_back(edges[i][1]);

        }
        
        if(n <= 1){
            if(edges.size())
                return false;
            else
                return true;
        }
        
        vector<bool> visited(n, false);
        vector<bool> visiting(n, false);
                
        return dfs(source, destination, adj_list, visited, visiting);
        
    }
};