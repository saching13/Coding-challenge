#include <iostream>
#include <string>
#include <vector>
using namespace std;

int deletionDistance( const string& str1, const string& str2 ) 
{

  vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, INT_MAX));
  
  dp[0][0] = 0;
  
  for(int i = 1; i <= str1.size(); ++i){
    dp[i][0] = dp[i - 1][0] + 1;
  }
 
  for(int i = 1; i <= str2.size(); ++i){
    dp[0][i] = dp[0][i - 1] + 1;

  }  

  for(int i = 1; i <= str1.size(); ++i){
    for(int j = 1; j <= str2.size(); ++j){
        if(str1[i - 1] == str2[j - 1]){ 
          dp[i][j] = dp[i - 1][j - 1];
                                      }
        else {
          dp[i][j] = min(dp[i-1][j] + 1, dp[i][j - 1] + 1);

        }
    }
  }

  return dp[str1.size()][str2.size()];
}

int main() {
  
string str1 = "dog", str2 = "frog";
 if(deletionDistance(str1, str2 ) == 3) cout << "Case 1 passed" << endl;
  str1 = "some", str2 = "some";
 if(deletionDistance(str1, str2 ) == 0) cout << "Case 2 passed" << endl;
  str1 = "some", str2 = "thing";
 if(deletionDistance(str1, str2 ) == 9) cout << "Case 3 passed" << endl;
  str1 = "", str2 = "";
 if(deletionDistance(str1, str2 ) == 0) cout << "Case 4 passed" << endl;
  
  
  return 0;
}