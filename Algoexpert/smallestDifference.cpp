#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	int smallest = INT_MAX, arrayOne_index = 0, arrayTwo_index = 0;
	int a,b;
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	while(arrayOne_index < arrayOne.size() && arrayTwo_index < arrayTwo.size()){
		int current_diff = abs(arrayOne[arrayOne_index] - arrayTwo[arrayTwo_index]);
		if(current_diff < smallest){
			smallest = current_diff;
			a = arrayOne[arrayOne_index];
			b = arrayTwo[arrayTwo_index]; 
		}
		if(arrayOne[arrayOne_index] < arrayTwo[arrayTwo_index]){
			arrayOne_index++;
		}
		else{
			arrayTwo_index++;
		}
	}
	//cout << a << " " << b <<endl;
	return {a,b};
}
