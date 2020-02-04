#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways(n+1,0);
	ways[0] = 1;
	for(int i = 0; i < denoms.size(); i++){
	  for(int amount = 1; amount < ways.size(); amount++){
			if(amount >= denoms[i]){
				ways[amount] += ways[amount - denoms[i]];
			}
		}
	}
	return ways[n];
}
