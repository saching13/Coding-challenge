#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  // Write your code here.
	vector<vector<int>> listSubSeq;
	for(int i = 0; i < array.size(); i++){
		
		listSubSeq.push_back({array[i]});
	}
	vector<int> listMaxSumInc(array);
	int maxSum = array[0];
	vector<int> maxSubSeq(listSubSeq[0]);

	for(int i = 0; i < array.size(); i++){
			for(int j = 0; j < i; j++){
					if(array[i] > array[j] && listMaxSumInc[j] + array[i] >= listMaxSumInc[i])
					{
						int sum = listMaxSumInc[j] + array[i];
						vector<int> temp = listSubSeq[j];
						temp.push_back(array[i]);
						listMaxSumInc[i] = sum;
						listSubSeq[i] = temp;
					}
				}
					if(listMaxSumInc[i] >= maxSum){
						maxSum = listMaxSumInc[i];
						maxSubSeq = listSubSeq[i];
						
					}
}
	
  return {{maxSum}, maxSubSeq};
}
