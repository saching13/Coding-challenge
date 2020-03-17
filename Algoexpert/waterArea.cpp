#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
	if (heights.size() == 0) return 0;
	int totalAera = 0;
//	vector<int> dpArea(heights.size(), 0);
	vector<int> leftMax(heights.size(), 0);
	vector<int> rightMax(heights.size(), 0);
	
	for(int i = 1; i < heights.size(); i++){
		leftMax[i] = max(leftMax[i - 1], heights[i - 1]);
  }
	
	for(int i = heights.size() - 2; i >= 0; i--){
		rightMax[i] = max(rightMax[i + 1], heights[i + 1]);
	}

	for(int k = 0; k < heights.size(); k++){
		int minMaxHeight = min(leftMax[k], rightMax[k]);
		if( minMaxHeight > heights[k]) totalAera = totalAera + minMaxHeight - heights[k];
		else totalAera = totalAera;
	}
	
  return totalAera;
}
