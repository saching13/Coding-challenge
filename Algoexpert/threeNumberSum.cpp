#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(),array.end());
	vector<vector<int>> result;
	int min_index, max_index;
	int sum;
	for(int i = 0; i < array.size(); i++){
		min_index = i + 1;
		max_index = array.size() - 1;
		while(min_index < max_index){
			sum = array[i] + array[min_index] + array[max_index];
			if(sum == targetSum){
				result.push_back({array[i], array[min_index], array[max_index]});
				min_index++;
				max_index--;
			}
			else if(sum < targetSum){
				min_index++;
			}
			else{
				max_index--;
			}
		}
	}
	return result;
}
