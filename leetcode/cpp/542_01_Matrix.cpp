
// TODO: Time limit exceeds -> Scroll down to check another solution

class Solution {
    vector<pair<int,int>> action_space(int r, int c, int rows, int cols){
        vector<pair<int,int>> offset{{-1,0},{1,0},{0,-1},{0,1}};
        vector<pair<int,int>> actions;

        for(pair<int,int> ofs : offset){
            if(r + ofs.first >= 0 && r + ofs.first < rows && c + ofs.second >= 0 && c + ofs.second < cols){
                actions.push_back({r + ofs.first, c + ofs.second});
            }
        }
            return actions;
    }
    
    void bfs(int r, int c, vector<vector<int>>& matrix, int rows, int cols){

        
        for(pair<int,int> act : action_space(r,c,rows,cols)){
            int r_sub = act.first;
            int c_sub = act.second;


             if(matrix[r_sub][c_sub] > matrix[r][c]  + 1){
                matrix[r_sub][c_sub] = matrix[r][c]  + 1;
                bfs(r_sub,c_sub,matrix, rows, cols);
            }
            

        }
        return;
    }
    
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size()) return matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(matrix[r][c] == 1)
                    matrix[r][c] = INT_MAX;                
            }
        }
        
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(matrix[r][c] == 0){
                    bfs(r,c,matrix, rows, cols);
                }
            }
        }

        
        
        return matrix;
    }
};



// Solution 2: BFS with loading all zeros at once as starting nodes i.e as level 0

class Solution {
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size()) return matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
                            // cout << "indf" << endl;
        queue<pair<int, int>> node_que;

        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(matrix[r][c] == 1)
                    matrix[r][c] = INT_MAX;
                if(matrix[r][c] == 0)
                    node_que.push({r,c});                
            }
        }
        vector<pair<int,int>> offset{{-1,0},{1,0},{0,-1},{0,1}};

        int r = 0, c = 0;
        while(!node_que.empty()){
            pair<int, int> curr_node = node_que.front();
            node_que.pop();
            r = curr_node.first;
            c = curr_node.second;
            
            
            for(int i = 0; i < 4; ++i){
                int r_sub = r + offset[i].first, c_sub = c + offset[i].second;
                if(r_sub >= 0 && r_sub < rows && c_sub >= 0 && c_sub < cols){
                     if(matrix[r_sub][c_sub] > matrix[r][c]  + 1){
                        matrix[r_sub][c_sub] = matrix[r][c]  + 1;
                        node_que.push({r_sub, c_sub});
                    }
                }
                
            }
            

            
        }
        
        
        return matrix;
    }
};