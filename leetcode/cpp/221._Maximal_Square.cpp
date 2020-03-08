class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        vector<vector<int>> side_length(matrix.size(), vector<int>(matrix[0].size(),0));
        int max_square_size = 0;
        
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){

                if(matrix[row][col] == '1'){
                    if(row == 0) side_length[row][col] = 1;
                    else if(col == 0) side_length[row][col] = 1;
                    else {
                    side_length[row][col] = min(side_length[row - 1][col - 1],\
                                            min(side_length[row - 1][col], side_length[row][col - 1])) + 1;                    
                    }
                    max_square_size = max(max_square_size, side_length[row][col]);                
                }
            }
        }
        
        return max_square_size*max_square_size;
        
    }
};