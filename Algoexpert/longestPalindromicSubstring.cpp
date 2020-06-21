using namespace std;

string longestPalindromicSubstring(string str) {
	if (str.size() <= 1) return str;
  	string max_str = str.substr(0,0);
	
	int max_len = 1;
	int left,right;
	
	for(int center = 1; center < 2 * str.size()-1; center++){
		left = center / 2;
		right = left + (center % 2);
		while((left >= 0 && right < str.size()) && (str[left] == str[right])){
				if(max_len < right + 1 - left){
					max_len = right + 1 - left;
					max_str = str.substr(left, right - left + 1);
				}
				left--;
				right++;
		}
	}
	return max_str;
}
	
	
	
	
	
	
	
 	
	
	
