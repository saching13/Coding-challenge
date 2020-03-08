#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
	unordered_map<string, vector<string>> anagram;
	vector<vector<string>> result;
	
	for(string word : words){
		string sortedWord = word;
		sort(sortedWord.begin(), sortedWord.end());
		anagram[sortedWord].push_back(word);
	}
	
	for(auto map : anagram) result.push_back(map.second);
	
return result;
}
