class Solution {
public:
    
    double findedges(unordered_map<string, 
                     vector<pair<string, double>>>& adj_list,
                     unordered_map<string, bool>& visited,
                     string& dest_node,
                     string& input_node){
                
        for(pair<string, double>& conn_node : adj_list[input_node]){
            cout << conn_node.first << endl;
            if(conn_node.first == dest_node){
                
                return conn_node.second;
            }
            else{
                if(adj_list.find(conn_node.first) != adj_list.end() && !visited[conn_node.first]){
                   visited[conn_node.first] = true;
                    double val = findedges(adj_list, visited, dest_node, conn_node.first);
                    visited[conn_node.first] = false;
                    if(val == -1) continue;
                    else return conn_node.second*val;
                }
            }
        }
            
        return -1;
        
    }
    
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    
        unordered_map<string, vector<pair<string, double>>> adj_list;
        unordered_map<string, bool> visited;
        
        for(int i = 0; i < equations.size(); ++i){
            if(adj_list.find(equations[i][0]) == adj_list.end()){
                    adj_list[equations[i][0]] = {{equations[i][1], values[i]}};
                    
            }
            else{
                    adj_list[equations[i][0]].push_back({equations[i][1], values[i]});
            
            }

             if(adj_list.find(equations[i][1]) == adj_list.end()){
                    adj_list[equations[i][1]] = {{equations[i][0], (double)(1/values[i])}};
            }
            else{
                    adj_list[equations[i][1]].push_back({equations[i][0], (double)(1/values[i])});
            }
            
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        
        
        
        vector<double> res;
        for(int i = 0; i < queries.size(); ++i){
            
            if(visited.find(queries[i][0]) == visited.end() || visited.find(queries[i][1]) == visited.end()){
                res.push_back(-1);
                continue;
            }
            else if(queries[i][0] == queries[i][1]){
                res.push_back(1);
                continue;
            }
                
            double val1 = -1;
            if(adj_list.find(queries[i][0]) != adj_list.end()){
                visited[queries[i][0]] = true;
                 val1 = findedges(adj_list, visited, queries[i][1], queries[i][0]);
                
                visited[queries[i][0]] = false;
            }

                res.push_back(val1);            
        }
        
        return res;
        
    }
};