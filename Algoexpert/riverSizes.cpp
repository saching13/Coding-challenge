#include <vector>
using namespace std;

//Helper recursive function
void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j, int &val){
	
		if(i-1 >= 0 && matrix[i-1][j] == 1 && !visited[i - 1][j]){
			visited[i-1][j] = true;
			val++; 
			dfs(matrix, visited, i - 1, j, val); //TODO: Dont write val+1 since it is passing as reference
		}
	
		if(j-1 >= 0 && matrix[i][j - 1] == 1 && !visited[i][j - 1]){
			visited[i][j-1] = true;
			val++; 
			dfs(matrix, visited, i, j - 1, val);
		}
	
		if(i + 1 < matrix.size() && matrix[i + 1][j] == 1 && !visited[i + 1][j]){
			visited[i + 1][j] = true;
			val++; 
			dfs(matrix, visited, i + 1, j, val);
		}
	
		if(j + 1 < matrix[0].size() && matrix[i][j + 1] == 1 && !visited[i][j + 1]){
			visited[i][j + 1] = true;
			val++; 
			dfs(matrix, visited, i, j + 1, val);
		}
	
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	int rows = matrix.size();
	int columns = matrix[0].size();
	vector<vector<bool>> visited(rows,vector<bool>(columns,false));
	vector<int> result;
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < columns; col++){
			if(matrix[row][col] == 1 && !visited[row][col])
			{	
				visited[row][col] = true;
				int val = 1;
				dfs(matrix, visited, row, col, val);
				result.push_back(val);
			}
		}
	}
	
	return result;
}
