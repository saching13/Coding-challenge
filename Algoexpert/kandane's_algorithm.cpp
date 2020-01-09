#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
	//vector<int> max_list_map;
	int max_ending = 0, max_sum = -1;
	
	//max_ending = max()
	for(int i=0; i < array.size(); i++){
		max_ending = max(array[i],array[i]+max_ending);
		max_sum = max(max_ending, max_sum); 
	}
	
	return max_sum;
	
}
