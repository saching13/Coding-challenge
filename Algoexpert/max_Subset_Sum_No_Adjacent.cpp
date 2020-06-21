#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
	vector<int> max_list;
	int len = array.size();
	if (len == 0)
		return 0;
		
	for(int i=0; i < len; i++){
		if (i == 0) {
			max_list.push_back(array[i]);
			}
		else if (i == 1 ){
			if(array[i] > array[i-1]) max_list.push_back(array[i]);
			else max_list.push_back(array[i-1]);
			}
	 	else{
		 	max_list.push_back(std::max(max_list[i-1],max_list[i-2]+array[i]));
		}	
	}
	
	if(max_list.size() >= len)
		return max_list[len-1];
	else
  	return 0;
}
