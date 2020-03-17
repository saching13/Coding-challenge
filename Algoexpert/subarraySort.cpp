// Copmlexity O(n). There is still space for some optimization.
// try to fond both min and max value in the same loop

#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> array) {
	int length = array.size();
	bool foundUnsorted = false;
	int minValue = -1 , maxValue = -1;
	pair<int, int> result = {-1,-1};
	bool minSet = false;

	for(int i = 1; i < length; ++i){
		if(!foundUnsorted && array[i - 1] > array[i]){
				foundUnsorted = true;
				minValue = array[i];
		}
		else{
			if(foundUnsorted && array[i] < minValue) minValue = array[i];
		}
	}
	
	foundUnsorted = false;
	for(int j = length -2; j >= 0; --j){
		if(!foundUnsorted && array[j] > array[j + 1] ){
				foundUnsorted = true;
				maxValue = array[j];
		}
		else{
			if(foundUnsorted && array[j] > maxValue) maxValue = array[j];
		}
	}

	if(minValue == -1 && maxValue == -1) return {-1, -1};
	
	for(int k = 0; k < length; ++k){
		if(!minSet && array[k] > minValue){
			result.first = k;
			minSet = true;
		}
		if(array[k] < maxValue){
			result.second = k ;
			maxSet = true;
		}
	}

	return {result.first, result.second};
}
