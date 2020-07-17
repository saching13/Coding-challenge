#include<queue>

class Solution {
    void bfs(int r, int c,vector<vector<int>>& A){
     
        vector<pair<int, int>> action_space{{-1,0},{1,0},{0,-1},{0,1}};
        A[r][c] = -1;
        queue<pair<int, int>> nodes;
        nodes.push(make_pair(r,c));
        
        while(!nodes.empty()){
            
            pair<int,int> curr_node = nodes.front();
            nodes.pop();

            int curr_r = curr_node.first;
            int curr_c = curr_node.second;
            

            for(auto& action : action_space){
                int dr = action.first;
                int dc = action.second;
                int next_r = curr_r + dr;
                int next_c = curr_c + dc;

                if(next_r >= 0 && next_r < A.size() && next_c >= 0 && next_c < A[0].size() && A[next_r][next_c] == 1){
                    A[next_r][next_c] = -1;
                    nodes.push(make_pair(next_r,next_c));
                    
                }
            }
        }
    }
    
    
public:
    int numEnclaves(vector<vector<int>>& A) {
        int row_min = 0;
        int col_min = 0;
        int row_max = A.size();
        int col_max = A[0].size();
        
        for(int c = 0; c < col_max; ++c){
            if(A[row_min][c] == 1)
            bfs(row_min, c, A);
        }
        
        for(int c = 0; c < col_max; ++c){
            if(A[row_max - 1][c] == 1)
            bfs(row_max - 1, c, A);
        }
        
        
        for(int r = row_min + 1; r < row_max - 1; ++r){
            if(A[r][col_min] == 1)
                bfs(r, col_min, A);
        }
        
        
        for(int r = row_min + 1; r < row_max - 1; ++r){
            if(A[r][col_max - 1] == 1)
                bfs(r, col_max - 1,  A);
        }
        
        int count = 0;
        for(int r = 0; r < row_max; ++r){
            for(int c = 0; c < col_max; ++c){
                if(A[r][c] == 1)
                    count++;
            }
        }
        return count;
        
        
    }
};