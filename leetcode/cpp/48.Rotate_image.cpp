class Solution {
public:
    
    void swap(int row,int col, int i, int j, vector<vector<int>>& matrix ){
        
        int next_val;
        int temp;
        int next_row = row + j;
        int next_col = col - i;
        next_val = matrix[next_row][next_col];
        matrix[next_row][next_col] = matrix[i][j];
        i = next_row;
        j = next_col;
    //    cout << "next row:" << i << " Next Col :" << j << "Value :" << matrix[next_row][next_col] <<   endl;
            
        for(int k = 1; k < 4; k++ ){
            next_row = row + j;
            next_col = col - i;
            temp = matrix[next_row][next_col];
            matrix[next_row][next_col] =next_val;
            next_val = temp;
            
            i = next_row;
            j = next_col;
    //        cout << "next row:" << i << " Next Col :" << j << "Value :" << matrix[next_row][next_col] <<   endl;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int col_size_limit = columns - 1;
        int row = 0,col = columns - 1;
        
        for(int i = 0;i < rows / 2; i++){
            for(int j = i; j < col_size_limit; j++){
                //cout << "swap 1 row :" << i << " Col:" << j << endl;
                swap(row, col, i, j, matrix);
            }
            col_size_limit--;
            
        }
        
    }
};