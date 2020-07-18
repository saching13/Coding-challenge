class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> nodes;
        vector<pair<int, int>> action_space{{0,-1},{1,0},{0,1},{-1,0}};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                    nodes.push(make_pair(i,j));
                }
                else{
                    grid[i][j] = INT_MAX;
                }
            }
        }
        
        int curr_dist = 0;
        while(!nodes.empty()){
            pair<int, int> curr_node = nodes.front();
            nodes.pop();
            
            int r = curr_node.first;
            int c = curr_node.second;
            
            if(grid[r][c] == -1) curr_dist = 0;
            else curr_dist = grid[r][c];
            
            for(auto& action : action_space){
                int next_r = r + action.first;
                int next_c = c + action.second;
                
                if(next_r >= 0 && next_r < grid.size() && next_c >= 0 && next_c < grid[0].size() && grid[next_r][next_c] != -1){
                    if(grid[next_r][next_c] > curr_dist + 1){
                        grid[next_r][next_c] = curr_dist + 1;
                        nodes.push(make_pair(next_r,next_c));
                    }
                    
                }
                
            }
            
            
            
        }
        
        int max_val = -1;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] != -1 && grid[i][j] != INT_MAX){
                    max_val = max(max_val, grid[i][j]);
                }
            }
        }
        return max_val;
        
    }
};