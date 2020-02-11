#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	sort(array.begin(),array.end());
	int left = 0;
	int right = array.size()-1;
	
	while(right > left){
		if(array[left] == toMove){
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
		else {//if(array(left != toMove))
		  
			left++;
		}
	}
	
	return array;
}
