#include <vector>
#include <unordered_map> 

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	// use sets insted if maps if we need the values insted of index
	unordered_map<int, int> reminder_index; 
	for(int i=0;i < array.size();i++){
		int rem = targetSum - array[i];
		
		if(reminder_index.find(array[i]) == reminder_index.end())
			reminder_index[rem] = i;
		else
		return {rem,array[i]};
	}
	
	return {};
}
