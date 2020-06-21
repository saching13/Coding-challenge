using namespace std;

int longestPeak(vector<int> array) {
  // Write your code here.
	int finalLongestPeak = 0;
	int longestPeak = 0;
	if(array.size() <= 1) return 0;
	bool PeakIncreasing = true;
	
	for(int i = 1; i < array.size(); ++i){

		if(array[i - 1] == array[i]){
			longestPeak = 0;
			PeakIncreasing = true;
			continue;
		}
		bool increasing = (array[i - 1] < array[i]);
		
		if(PeakIncreasing && increasing) longestPeak++;
		else if(PeakIncreasing && longestPeak > 0 && !increasing){ 
			longestPeak++;
			PeakIncreasing = false;
			finalLongestPeak = max(finalLongestPeak, longestPeak + 1);
			}
		else if(!PeakIncreasing && !increasing){ 
				longestPeak++;
			cout << array[i] << " " << longestPeak << endl;
				finalLongestPeak = max(finalLongestPeak, longestPeak + 1);
			}
		else if(!PeakIncreasing && increasing){ 
			finalLongestPeak = max(finalLongestPeak, longestPeak + 1);
			longestPeak = 1;
			PeakIncreasing = true;}
		
	}
  return finalLongestPeak;
}
