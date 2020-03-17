#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
vector<int> dp(array.size(),INT_MAX);
	
	dp[0] = 0;
	
	for(int i = 0; i < array.size(); i++){
		for(int j = i + 1; j <= i + array[i] ; j++){
			if(j >= array.size()) break;
			dp[j] = min(dp[i] + 1,dp[j]);
		}
}
	
	
	return dp[array.size() - 1] ;
}
