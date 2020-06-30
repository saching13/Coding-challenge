class Solution {
public:
    // 'alive -> dead => 1 -> 0 => 1 -> -1' || 'dead -> alive => 0 -> 1 => 0->2'
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<pair<int, int>> neighbours{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                int count_alive_neigh = 0;
                for(pair<int,int> del_change : neighbours){
                    int dx = del_change.first;
                    int dy = del_change.second;
                    int nei_x = i + dx;
                    int nei_y = j + dy;
                    if(nei_x >= 0 && nei_x < board.size() && nei_y >= 0 && nei_y < board[0].size()){
                        if(board[nei_x][nei_y] == 1 || board[nei_x][nei_y] == -1) count_alive_neigh += 1;
                    }
                }
                if(count_alive_neigh < 2){
                    if(board[i][j] == 1) board[i][j] = -1;
                }
                else if(count_alive_neigh == 3){
                    if(board[i][j] == 0) board[i][j] = 2;
                }
                else if(count_alive_neigh > 3){
                    if(board[i][j] == 1) board[i][j] = -1;
                }
                
                
            }
        }
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
            
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] = 1;
                
            }
        }
        
        
    }
};


