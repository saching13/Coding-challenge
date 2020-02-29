#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	unordered_map<int, vector<pair<int,int>>> sum_list;
	vector<vector<int>> result;
	for(int i = 0; i < array.size()-1; i++){
		for(int j = i+1; j < array.size(); j++){
			int diff = targetSum - (array[i] + array[j]);
			
			
			if (sum_list.find(diff) != sum_list.end()){				
				for(pair<int,int> tuple : sum_list[diff]){
					vector<int> temp = {array[i],array[j],tuple.first,tuple.second};
					if(find(result.begin(), result.end(),temp) == result.end())
							result.push_back(temp);	
				}
			}
		}
		
		for(int k = 0; k < i; k++){
			int sum = array[i]+array[k];
			if (sum_list.find(sum) == sum_list.end()) sum_list[sum] = { {array[i], array[k]} };
			else sum_list[sum].push_back({array[i], array[k]});
		}
	}
	
	
  return result;
}
