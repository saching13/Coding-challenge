// This is one way to solve the problem with two arrays and 
// we need all the ways to check which gives minimum in total.

// This problem can also be solved with out 2D array. 
// Insted of that we can use only last two rows. by updating each of them in even and odd iterations 
// This reduces the O(mn) space complexity to O(min(m,n))

using namespace std;

int levenshteinDistance(string str1, string str2) {
	vector<vector<int>> edits(str1.length()+1, vector(str2.length()+1, 1));
	
  for(int i=0; i <= str2.length(); i++ ){
		edits[0][i] = i;
	}	
	for(int i=0; i <= str1.length(); i++ ){
		edits[i][0] = i;
	}	
	
	for(int row = 1; row <= str1.length(); row++ ){
			for(int col=1; col <= str2.length(); col++ ){
				
				if(str1[row-1] == str2[col-1]){
					 edits[row][col] = edits[row-1][col-1];
				 }
				 else{
					 edits[row][col] = 1 + min(edits[row-1][col], min(edits[row][col-1], edits[row-1][col-1]));
				 }
			}
	}
	
	
	return edits[str1.length()][str2.length()];
}

