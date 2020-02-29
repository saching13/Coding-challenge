// 62. Unique Paths

class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>> path_matrix(n, vector<int>(m, 0)); // here we consider m as column and n as row
        
    path_matrix[0][0] = 1; // DP matrix for min unique paths
        
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(row == 0 && col ==0) continue;
            //cout << "row" << row << "col:" << col << endl;
            if(row - 1 < 0) path_matrix[row][col] = path_matrix[row][col - 1];
            else if(col - 1 < 0) path_matrix[row][col] = path_matrix[row - 1][col];
            else path_matrix[row][col] = path_matrix[row - 1][col] + path_matrix[row][col - 1];;
        }    
    }
    
        
        
        return path_matrix[n - 1][m - 1];
    }
};