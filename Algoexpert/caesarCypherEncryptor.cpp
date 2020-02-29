#include<string>
using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  int val;
	
	key = key % 26;
	
	for(int i = 0; i < str.length(); i++){
		val = int(str[i]) + key;
		if( val > 122){
			val = (val % 123) + 97;
		}
		cout << str << endl;
		str[i] = char(val);
	}
	return str;
}
