#include<cmath>
// A star Solution.
class Solution {
    
    using pi = pair<double, int>;
    
    int get_serialized_index(int r, int c, int max_r, int max_c){
        return max_c * r + c;
    }
    
    pair<int, int> get_unserialized_index(int idx, int max_r, int max_c){
        
        int col = idx % max_c;
        int row = idx / max_c;
        return make_pair(row, col);
    }
    
    double heuristic(int r, int c, int dest_r, int dest_c){
        
        return max(abs(r-dest_r), abs(c - dest_c));
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid.size() == 0) return 0;
        
        if(grid.size() == 1 && grid[0].size() == 1){
            if(grid[0][0] == 0)
            return 1;
            else return -1;
        }
        bool isFound = false;
        
        int dest_r = grid.size() - 1;
        int dest_c = grid[0].size() - 1;
        
        vector<int> path(grid.size()* grid[0].size(), -1);
        vector<double> curr_dist(grid.size()* grid[0].size(), INT_MAX);
        vector<pair<int, int>> action_space{{0,-1},{0,1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
        
        priority_queue<pi, vector<pi>, greater<pi>> nodes;
        if(grid[0][0] == 0){
            nodes.emplace(heuristic(0, 0, dest_r, dest_c),0);
        }
        curr_dist[0] = 0;
        
        while(!nodes.empty()){
            pi curr_node = nodes.top();
            nodes.pop();
            int serialized_index = curr_node.second;
            
            if(serialized_index == (grid.size() * grid[0].size()) - 1){
                isFound = true;
                break;
            }
            
            pair<int,int> idx = get_unserialized_index(serialized_index, grid.size(), grid[0].size());
            
            int r = idx.first;
            int c = idx.second;
            
            for(int i = 0; i < action_space.size(); ++i){
                int curr_r = r + action_space[i].first;
                int curr_c = c + action_space[i].second;
                
                if(curr_r >= 0 && curr_r < grid.size() && curr_c >= 0 && curr_c < grid[0].size() && grid[curr_r][curr_c] != 1){
                    int neigh_ser_index = get_serialized_index(curr_r, curr_c, grid.size(), grid[0].size());
                    if(curr_dist[serialized_index] + 1 <  curr_dist[neigh_ser_index]){
                        curr_dist[neigh_ser_index] = curr_dist[serialized_index] + 1;
                        double h_dist = curr_dist[neigh_ser_index] + heuristic(curr_r, curr_c, dest_r, dest_c);                               path[neigh_ser_index] = serialized_index;
                        nodes.emplace(h_dist, neigh_ser_index);
                    }
                }
            }
            
        }
        int count = 1;
        int curr_node = (grid.size() * grid[0].size()) - 1;
    
        if(!isFound) return -1;
        while(curr_node != 0){
            pair<int,int> idx = get_unserialized_index(curr_node, grid.size(), grid[0].size());

            curr_node = path[curr_node];
            count++;
            
        }
        
        return count;
    }
};