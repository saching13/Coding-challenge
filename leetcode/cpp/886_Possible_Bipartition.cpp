
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj_list, vector<int>& nodes, int type, int curr_node){
        nodes[curr_node] = type;
        if(adj_list.find(curr_node) == adj_list.end()) return true;
        
        for(int next_node : adj_list[curr_node]){
            if(nodes[next_node] == -1){
               if(!dfs(adj_list, nodes, !type, next_node)) return false;
            }
            else if(nodes[next_node] != !type){
                return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> visited(N + 1, -1);
        unordered_map<int, vector<int>> adj_list;
            
        for(vector<int> edge : dislikes){
            if(adj_list.find(edge[0]) == adj_list.end()){
                adj_list[edge[0]] = {edge[1]};
            }
            else{
                adj_list[edge[0]].push_back(edge[1]);
            }
            
            if(adj_list.find(edge[1]) == adj_list.end()){
                adj_list[edge[1]] = {edge[0]};
            }
            else{
                adj_list[edge[1]].push_back(edge[0]);
            }
        }
                
        for(int i = 1; i <= N; ++i){
            if(visited[i] == -1)
            if(!dfs(adj_list, visited, 0, i)) return false;
            
        }
        
        return true;
    }
};