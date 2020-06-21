#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
};

// creating edges that are parallel to Y axis
void createEdges(vector<pair<Point, Point>>& edgesParallelToY, vector<Point>& coords){
	for(int i = 0; i < coords.size() - 1; ++i){
		for(int j = i + 1; j < coords.size(); ++j){
			if(coords[i].x == coords[j].x) edgesParallelToY.push_back({coords[i], coords[j]});
			else break; // advantage of sorting is that we can break here
		}	
	}
}

// Checking if two sides parallel to y axis makes a rectangle

bool compare(pair<Point, Point>& a, pair<Point, Point>&b){
	return (a.first.y == b.first.y && a.second.y == b.second.y) || (a.first.y == b.second.y && a.second.y == b.first.y);
}

// checking all the rectangles using n^2 loop
int getRectangles(vector<pair<Point, Point>>& edgesParallelToY){
	if(edgesParallelToY.size() < 2) return 0;
	int totalRectangles = 0;
	for(int i = 0; i < edgesParallelToY.size() - 1; ++i){
		for(int j = i + 1; j < edgesParallelToY.size(); ++j){
			if(compare(edgesParallelToY[i],edgesParallelToY[j])) totalRectangles++;
		}	
	}
	return totalRectangles;
}

int rectangleMania(vector<Point> coords) {
	if(coords.size() < 4) return 0;
	
	// Sorting helps in recuding computation later in n^2 loop to get edges
	sort(coords.begin(), coords.end(),[](Point& a, Point& b){ return (a.x < b.x);});
	
	vector<pair<Point, Point>> edgesParallelToY;
	createEdges(edgesParallelToY, coords);
	
	
	return getRectangles(edgesParallelToY);
}
