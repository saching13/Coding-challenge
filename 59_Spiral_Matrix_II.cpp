class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    
        int value = 1;
        int row_max = n-1;
        int row_min = 0;
        int col_min = 0;
        int col_max = n-1;
        vector<vector<int>> matrix(n, std::vector<int>(n, 0));
        
        while(row_min <= row_min && col_min <= col_max){
            
            for(int i = col_min;i <= col_max;i++){
                
                matrix[row_min][i] = value;
                value++;
               
            }
             row_min++;        
            for(int i = row_min;i <= row_max;i++){
                
                matrix[i][col_max] = value;
                value++;
                
            }
                col_max--;
            
            for(int i = col_max;i >= col_min;i--){
                matrix[row_max][i] = value;
                value++;

            }
                row_max--;            
            for(int i = row_max;i >= row_min;i--){
                
                matrix[i][col_min] = value;
                value++;
                
                
            }
            col_min++;
            
            
        }
        
        return matrix;
        
    }
};