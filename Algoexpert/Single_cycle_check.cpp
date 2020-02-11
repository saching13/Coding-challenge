using namespace std;

bool hasSingleCycle(vector<int> array) {
	int size = array.size();	
	vector<int> visited(size,0);
	int next_index = 0;	
	
	while(visited[next_index] != 1)
	{
		visited[next_index] = 1;
		next_index += (array[next_index] % size);
		
		if(next_index < 0){
			 next_index = size + next_index;
		}
		else if(next_index >= size){
			next_index = next_index % size;
		}
	}
	
for( int check_visited: visited){
		if(check_visited != 1){
			return false;
	}
}
	
	if(next_index != 0){
		return false;
	}
	return true;
}
