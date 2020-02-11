#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	vector<int> min_num_of_coins(n+1,INT_MAX);
	int to_compare = 0;
	min_num_of_coins[0] = 0;
	for(int denom : denoms){
		for(int amount = 1; amount < min_num_of_coins.size(); amount++){
			if(denom <= amount){
				if(min_num_of_coins[amount-denom] == INT_MAX){
					to_compare = min_num_of_coins[amount-denom];}
				else{
					to_compare = min_num_of_coins[amount-denom] + 1;}
				min_num_of_coins[amount] = min(min_num_of_coins[amount], to_compare);
			}
		}
	}
	
	return (min_num_of_coins[n] == INT_MAX) ? -1: min_num_of_coins[n];
}
